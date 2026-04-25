
#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ranges>
#include<deque>
#include <limits>
#include <set>
#include <map>

typedef long long ll;
typedef long double ld;
using namespace std;

const int PERSON = 2;
int N,M;
int leftAnswer;

ll curOil;
int taxiY,taxiX;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1};

/*
getBestPerson() -> {승객행,승객열,승객픽업전_비용}
-> 구현은 BFS로
    -> 큐의 원소 : {행,열,누적거리}

-> 여러명일때 우선처리 하기 (행과 열의 곱으로 인덱스로 우선순위)
-> 승객이 아예 없는 경우 정답 출력
-> 최고로 고른 승객까지의 "픽업"거리가 연료보다 초과하면 -1 출력
*/
tuple<int,int,int> getBestPerson(vector<vector<int>>& v,int ty, int tx) {
    vector<vector<bool>> visited(N,vector<bool>(N));
    queue<tuple<int,int,int>> q;
    vector<tuple<int,int,int>> answerQ;
    visited[ty][tx] = 0;
    q.push({ty,tx,0});
    while (!q.empty()) {
        auto [y,x,acc] = q.front(); q.pop();
        // 사람이 있는 경우
        if (v[y][x] == PERSON) {
            // 이미 정답에 있는 경우 -> 만약 누적값이 정답 큐에 넣은것보다 크면 break
            if (!answerQ.empty() and get<2>(answerQ.front()) < acc) {
                break;
            }
            // 정답이 아직 없는경우 + 정답이 있지만 동일한 누적거리인 경우 추후 행과 열 비교 필요
            answerQ.push_back({y,x,acc});;
            continue;
        }

        // 이웃 순회
        for (int idx=0;idx<4;idx++) {
            int ny = y+dy[idx];
            int nx = x+dx[idx];
            if (ny<0 or nx<0 or ny>=N or nx>=N) continue;
            if (visited[ny][nx]) continue;
            if (v[ny][nx] == 1) continue; // 벽을 만난 경우
            visited[ny][nx] = true;
            q.push({ny,nx,acc+1});
        }
    }

    // 승객이아예없는경우
    if (answerQ.empty()) {
        cout << -1; // 남은연료양 출력
        exit(0);
    }


    // 승객이 있지만 가는 거리보다 연료가 부족한 경우
    // 이건 등호 들어가도 되는게 어차피 픽업하자마자 멈추는 경우도 고려 (어차피 출발지와 목적지는 다름)
    if (get<2>(answerQ.front()) >= curOil) {
        cout << -1;
        exit(0);
    }

    int bestRow = 2100000000;
    int bestCol = 2100000000;
    int beforeAcc = get<2>(answerQ.front());
    for (auto tp : answerQ) {
        auto [r,c,acc] = tp;
        // 현재 행이 best행보다 아래
        if (r<bestRow) {
            bestRow = r;
            bestCol = c;
        } else if (r==bestRow and bestCol > c) {
            bestRow = r;
            bestCol = c;
        }
        if (beforeAcc != acc) throw "not same";
    }
    if (bestRow == 2100000000 or bestCol == 2100000000) throw "err";
    return {bestRow,bestCol,beforeAcc};
}

void gotoDest(vector<vector<int>>& v,int startRow, int startCol, int destRow, int destC) {
    vector<vector<bool>> visited(N,vector<bool>(N));
    queue<tuple<int,int,int>> q; // {row,col,moveAcc}
    q.push({startRow,startCol,0});
    visited[startRow][startCol] = true;
    int useAcc = -1;
    while (!q.empty()) {
        auto [r,c,acc] = q.front(); q.pop();
        if (r==destRow and c==destC) {
            useAcc = acc;
            break;
        }

        // 이웃 순회
        for (int idx=0;idx<4;idx++) {
            int ny = r+dy[idx];
            int nx = c+dx[idx];
            if (ny<0 or nx<0 or ny>=N or nx>=N) continue;
            if (visited[ny][nx]) continue;
            if (v[ny][nx] == 1) continue; // 벽을 만난 경우
            visited[ny][nx] = true;
            q.push({ny,nx,acc+1});
        }

    }

    // 손님이 있지만 못태우러가는 경우
    if (useAcc == -1) {
        cout << "-1";
        exit(0);
    }

    // 이동 비용이 현재 오일보다 많은 경우
    if (useAcc > curOil) {
        cout << "-1";
        exit(0);
    }

    // 목적지로 이동 + 택시위치 갱신 + 오일 변화
    curOil += useAcc; // 오일변화 -> 충전까지 미리 고려
    taxiY = destRow;
    taxiX = destC;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> curOil;
    leftAnswer = M; // 남은 손님
    vector<vector<int>> v(N,vector<int>(N));
    vector<vector<pair<int,int>>> dest(N,vector<pair<int,int>>(N,{-1,-1}));
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> v[i][j];
        }
    }

    cin >> taxiY >> taxiX;
    taxiY-=1; // 행 열 -1 주의
    taxiX-=1; // 행 열 -1 주의

    // 행 입력 0주의
    for (int cnt=0;cnt<M;cnt++) {
        int tmpRow,tmpCol,destRow, destCol;
        cin >> tmpRow >> tmpCol >> destRow >> destCol;
        dest[tmpRow-1][tmpCol-1] = {destRow-1,destCol-1};
        v[tmpRow-1][tmpCol-1] = PERSON;
    }

    while (true) {
        auto [personR,personC,pickUpAcc] = getBestPerson(v,taxiY,taxiX);
        if (curOil < pickUpAcc) throw "err";
        // 픽업하러 가기
        /*
        goToPickup(row,col)
         */
        curOil -= pickUpAcc; //curOil부분 빼기
        taxiY = personR; // 택시 위치 갱신 + 픽업장소로 이동
        taxiX = personC;
        v[taxiY][taxiX] = 0; // 승객 좌표 빈칸처리

        // 도착지까지 이동 -> bfs고려
        auto [destR,destC] = dest[personR][personC];
        if (destR == -1 or destC == -1) throw "err"; // 초기화 안된 목적지
        gotoDest(v,personR,personC,destR,destC);
        leftAnswer--;
        if (leftAnswer == 0) {
            cout << curOil;
            exit(0);
        }
    }
}