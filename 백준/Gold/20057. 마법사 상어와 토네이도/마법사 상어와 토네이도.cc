#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;
// -----------------------------------------
int N;
int answer = 0;
vector<vector<int>> v;

queue<pair<int, int>> dydxDirQ;

bool isDebug = false;

queue<pair<int, int>> moveDYDX; // 이동할 양

class Change {
public:
    int ny;
    int nx;
    int addAmount;
};


void addNewYX(vector<Change>& changeVector,int dy, int dx, const int beforeAmount) {
    //curY += dy; // 바람이 실제 움직인거 고려
    //curX += dx;
    //if (swapTF) {
        //swap(curY, curX);
        //swap(dy, dx);
    //}

    int acc = 0;
    int ny, nx, addVal;
    bool isLeft = dy == 0 && dx == -1;
    bool isRight = dy == 0 && dx == 1;
    bool isUp = dy == -1;
    bool isDown = dy == 1;

    // 10% 영역 위쪽
    if (isLeft) {
        ny = -1;
        nx = -1;
    } else if (isRight) {
        ny = -1;
        nx = 1;
    } else if (isUp) {
        ny = -1;
        nx = 1;
    } else if (isDown) {
        ny = 1;
        nx = -1;
    }
    addVal = beforeAmount * 0.1;
    acc += addVal;
    changeVector.push_back({ ny,nx,addVal });

    // 10% 영역 아래쪽
    if (isLeft) {
        ny = +1;
        nx = -1;
    } else if (isRight) {
        ny = +1;
        nx = 1;
    } else if (isUp) {
        ny = -1;
        nx = -1;
    } else if (isDown) {
        ny = 1;
        nx = 1;
    }
    addVal = beforeAmount * 0.1;
    acc += addVal;
    changeVector.push_back({ ny,nx,addVal });

    // 7% 영역 위쪽
    if (isLeft) {
        ny = -1;
        nx = 0;
    } else if (isRight) {
        ny = -1;
        nx = 0;
    } else if (isUp) {
        ny = 0;
        nx = 1;
    } else if (isDown) {
        ny = 0;
        nx = -1;
    }
    addVal = beforeAmount * 0.07;
    acc += addVal;
    changeVector.push_back({ ny,nx,addVal });

    // 7% 영역 아래쪽
    if (isLeft) {
        ny = +1;
        nx = 0;
    } else if (isRight) {
        ny = 1;
        nx = 0;
    } else if (isUp) {
        ny = 0;
        nx = -1;
    } else if (isDown) {
        ny = 0;
        nx = 1;
    }
    addVal = beforeAmount * 0.07;
    acc += addVal;
    changeVector.push_back({ ny,nx,addVal });

    // 5% 영역
    if (isLeft) {
        ny = 0;
        nx = -2;
    } else if (isRight) {
        ny = 0;
        nx = 2;
    } else if (isUp) {
        ny = -2;
        nx = 0;
    } else if (isDown) {
        ny = 2;
        nx = 0;
    }
    addVal = beforeAmount * 0.05;
    acc += addVal;
    changeVector.push_back({ ny,nx,addVal });

    // 2% 영역 위쪽
    if (isLeft) {
        ny = -2;
        nx = 0;
    } else if (isRight) {
        ny = -2;
        nx = 0;
    } else if (isUp) {
        ny = 0;
        nx = 2;
    } else if (isDown) {
        ny = 0;
        nx = -2;
    }
    addVal = beforeAmount * 0.02;
    acc += addVal;
    changeVector.push_back({ ny,nx,addVal });

    // 2% 영역 아래쪽
    if (isLeft) {
        ny = +2;
        nx = 0;
    } else if (isRight) {
        ny = +2;
        nx = 0;
    } else if (isUp) {
        ny = 0;
        nx = -2;
    } else if (isDown) {
        ny = 0;
        nx = 2;
    }
    addVal = beforeAmount * 0.02;
    acc += addVal;
    changeVector.push_back({ ny,nx,addVal });


    // 1% 영역 1번
    if (isLeft) {
        ny = -1;
        nx = 1;
    } else if (isRight) {
        ny = -1;
        nx = -1;
    } else if (isUp) {
        ny = 1;
        nx = 1;
    } else if (isDown) {
        ny = -1;
        nx = -1;
    }
    addVal = beforeAmount * 0.01;
    acc += addVal;
    changeVector.push_back({ ny,nx,addVal });

    // 1% 영역 2번
    if (isLeft) {
        ny = +1;
        nx = 1;
    } else if (isRight) {
        ny = 1;
        nx = -1;
    } else if (isUp) {
        ny = 1;
        nx = -1;
    } else if (isDown) {
        ny = -1;
        nx = 1;
    }
    addVal = beforeAmount * 0.01;
    acc += addVal;
    changeVector.push_back({ ny,nx,addVal });


    // 알파영역
    if (isLeft) {
        ny = 0;
        nx = -1;
    } else if (isRight) {
        ny = 0;
        nx = +1;
    } else if (isUp) {
        ny = -1;
        nx = 0;
    } else if (isDown) {
        ny = 1;
        nx = 0;
    }
    addVal = beforeAmount-acc;
    if (addVal < 0)  throw "error";
    changeVector.push_back({ ny,nx,addVal });
}


void moveTornado(int& curWindY, int& curWindX) { // 참조자
    auto [dy, dx] = moveDYDX.front(); moveDYDX.pop();
    // 기존 지역 모레 삭제
    vector<Change> changeVector; // 변경 대상 지역
    if (dy >= 2 || dx >= 2 || dy <= -2 || dx<=-2) throw "error12";
    curWindY += dy;
    curWindX += dx;
    const int beforeAmount = v.at(curWindY).at(curWindX);

    if (isDebug) cout << "현재 위치 " << curWindY << "," << curWindX << "\n";

    addNewYX(changeVector,dy, dx, beforeAmount); // dy,dx가 현재 토네이도 방향
    for (Change& c : changeVector) {
        auto [ny, nx, addAmount] = c;
        int y = curWindY + ny;
        int x = curWindX + nx;
        // 밖으로 나가버리는 경우
        if (y < 0 || x < 0 || y >= N || x >= N) {
            answer += addAmount;
            if (isDebug) cout << "curAnswer : " << answer << "\n";
            continue;
        }
        v[y][x] += addAmount;
    }
    v[curWindY][curWindX] = 0;

    // 현재 상태
    if (isDebug) {
        cout << "----vector-----\n";
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }

    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dydxDirQ.push({ 0,-1 });
    dydxDirQ.push({ 1,0 });
    dydxDirQ.push({ 0,1 });
    dydxDirQ.push({ -1,0 });
    cin >> N;
    // 이동 벡터
    int nextConst = 1; // 토네이도 배수 
    bool doubleConst = false;
    int curMoveDirNotChange = 0;
    int moveDyDxCnt = 0;
    while (moveDyDxCnt < N*N -1) { // N*N -1 만큼만 이동
        if (curMoveDirNotChange == nextConst) {
            if (doubleConst) {
                nextConst++;
                doubleConst = false;
            } else {
                doubleConst = true;
            }
            curMoveDirNotChange = 0;
            // 방향 큐 순환
            auto topPair = dydxDirQ.front();
            dydxDirQ.pop();
            dydxDirQ.push(topPair);
            continue;
        }
        auto& topPair = dydxDirQ.front();
        int dy = topPair.first;
        int dx = topPair.second;
        moveDYDX.push({ dy, dx });
        curMoveDirNotChange++;
        moveDyDxCnt++;
    }


    v.assign(N, vector<int>(N));
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    int curWindY = N / 2;
    int curWindX = curWindY;
    while (!moveDYDX.empty()) {
        moveTornado(curWindY,curWindX);
    }

    cout << answer;

}