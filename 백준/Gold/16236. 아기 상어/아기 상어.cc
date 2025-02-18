#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <bitset>
typedef long long ll;
using namespace std;
// -----------------------------------------
// -----------------------------------------
// -----------------------------------------
int N;


vector<vector<int>> v;

int answer = 0;
class Shark {
public:
    int y=0;
    int x=0;
    int grade = 2;

    // 먹이 먹이기
    void feedCurrentYX() {
        acc++;
        if (acc == grade) {
            grade++;
            acc = 0;
        }
        if (v[this->y][this->x] == 0) throw "err";
        v[this->y][this->x] = 0; // 먹었으니 0으로

    }


private:
    int acc = 0; // 상어 포인트 누적

};

Shark s;
const int NONE = 100000000;

int dys[4] = { -1,0,1,0 };
int dxs[4] = { 0,-1,0,1 };

/*int bfsDistCurShark(int y, int x) {
    // 현재 상어와 특정 y,x까지의 거리
    queue<tuple<int, int, int>> q; // y,x,val
    vector<vector<bool>> visit(N, vector<bool>(N));
    int localDist = 0;
    visit[s.y][s.x] = true;
    int destY = y;
    int destX = x;
    q.push({ s.y,s.x,0 });
    bool find = false;
    while (!q.empty()) {
        auto [curY, curX, curVal] = q.front(); q.pop();
        if (curY == destY && curX == destX) {
            localDist += curVal;
            find = true;
            break;
        }

        // 만약에 원하는 좌표가 아닌 경우, 이동 대상 넣기
        for (size_t i = 0; i < 4; i++) {
            int dy = dys[i];
            int dx = dxs[i];
            int ny = dy + curY;
            int nx = dx + curX;
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            // 못가는 경우 : 상어의 grade를 초과하는 경우
            // 못가는 경우 : 이미 방문한 경우
            if (v[ny][nx] > s.grade) continue;
            if (visit[ny][nx]) continue;
            q.push({ ny,nx,curVal + 1 });
            visit[ny][nx] = true;
        }
    }

    if (!find) {
        return NONE;
    }
    return localDist;

    //불가능하면무한대리턴;
    //eatYXList순회할때무한대면continue;

//}*/

bool findBest() {
    // 여기에 가능한 좌표들 넣기 (y,x,value)
    //vector<tuple<int, int, int>> canEatYxList; 
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < N; j++) {
    //        if (v[i][j] > 0 && v[i][j] < s.grade) {
    //            canEatYxList.push_back({ i,j,v[i][j] });
    //        }
    //    }
    //}
    //

    //// 다 먹은 경우
    //if (canEatYxList.empty()) {
    //    cout << answer;
    //    return true;
    //}

    //sort(canEatYxList.begin(), canEatYxList.end(), [](auto tp1, auto tp2) {
    //    auto [y1, x1, val1] = tp1;
    //    auto [y2, x2, val2] = tp2;

    //    // 1. 거리가 가장 가까운 순서 
    //    int dist1 = bfsDistCurShark(y1, x1);
    //    int dist2 = bfsDistCurShark(y2, x2);

    //    if (dist1 != dist2) {
    //        return dist1 < dist2; // 거리가 작을수록 오름차순
    //    }

    //    // 2. 거리가 같다면? y축 정렬
    //    if (y2 != y1) {
    //        return y1 < y2; // y값이 작을수록 위쪽임 (y가 작을 수록 오름차순)
    //    }

    //    // 3. y도 같다면 x순서 (x가 작은 순서로 앞쪽)
    //    return x1 < x2;
    //    });

    // 하지만 정렬의 제일 앞이여도 못먹을 수 있음 (벽에 막히면)
    // 따라서 작은 경우부터 전체 순회   
    bool answerFind = false;
    //for (tuple<int,int,int> eatYX : canEatYxList) {
    //auto [destY, destX, destVal] = eatYX;
    // BFS로_경로_찾기
    queue<tuple<int, int, int>> q; // y,x,val
    vector<vector<bool>> visit(N, vector<bool>(N));
    visit[s.y][s.x] = true;
    q.push({ s.y,s.x,0 });
    //여기에서먹을수있는후보군을다넣고 그다음에 정렬;
    vector<tuple<int, int,int>> answerList; // 누적거리,Y,X
    while (!q.empty()) {
        auto [curY, curX, curVal] = q.front(); q.pop();
        // 일단 먹을 수 있는 경우 후보군에 추가
        if (v[curY][curX]  > 0 && v[curY][curX] < s.grade) {
            answerList.push_back({ curVal,curY,curX });
        }

        //-----아래수정-----
        //if (curY == destY && curX == destX) {
        //    answer += curVal; // 누적 이동거리 더하기
        //    s.y = curY; s.x = curX; // 좌표 갱신
        //    s.feedCurrentYX(); // 현재 위치에서 밥 먹이기
        //    break;
        //}

        // 만약에 원하는 좌표가 아닌 경우, 이동 대상 넣기
        for (size_t i = 0; i < 4; i++) {
            int dy = dys[i];
            int dx = dxs[i];
            int ny = dy + curY;
            int nx = dx + curX;
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            // 못가는 경우 : 상어의 grade를 초과하는 경우
            // 못가는 경우 : 이미 방문한 경우
            if (v[ny][nx] > s.grade) continue;
            if (visit[ny][nx]) continue;
            q.push({ ny,nx,curVal + 1 });
            visit[ny][nx] = true;
        }
    }
        //if (answerFind) break;
    //}

    // 아예 도달못하는 경우 생각해야됨(그래프상에 상어가먹을수있는건있지만_다막혀서못가는경우);
    //if (!answerFind) {
    if (answerList.empty()) {
        cout << answer;
        return true;
    }
    sort(answerList.begin(), answerList.end()); // y작은순 -> x작은순 자동정렬
    auto [minAns,minY,minX] = answerList[0];
    answer += minAns; // 누적 이동거리 더하기
    s.y = minY; s.x = minX; // 좌표 갱신
    s.feedCurrentYX(); // 현재 위치에서 밥 먹이기

    return false;

}


int main() {
    cin >> N;
    v.assign(N, vector<int>(N));


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 9) {
                s.y = i;
                s.x = j;
            }
        }
    }
    v[s.y][s.x] = 0; // 상어 위치 0으로
    
    while (1) {
        bool tf=findBest();
        if (tf) break;
    }
    return 0;
}