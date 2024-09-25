#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <unordered_set>

typedef long long ll;
using namespace std;
int N, M;
const int MAX_VAL = 2000000000;
int minAnswer = MAX_VAL;
int BLANK_CNT = 0;
int ADD_CONST = 3000;

int dxArr[] = { -1,1,0,0 };
int dyArr[] = { 0,0,1,-1 };

int getBestTime(vector<vector<int>>& v, vector<pair<int, int>>& realUse, unordered_set<int>& virusIndex) {
    //for (int i = 0; i < realUse.size(); i++) {
    //    auto [y, x] = realUse[i];
    //    v[y][x] = 2; // 2초시점으로 변경
    //}

    // 현재시간이 t초면, forloop돌면서 활성만들놈은 t, 다음번에 재활성될 자리는t+1;
    //int currentTime = 1; // 사실상 2초부터 시작한다고 가정
    int leftBlankCnt = BLANK_CNT; // 남은 "빈칸"의 개수
    if (leftBlankCnt == 0) {
        return 0;
    }
    queue<tuple<int, int,int>> q; // 활성 바이러스 queue - {y,x,시간}
    unordered_set<int> visit;
    //while (currentTime <= N * N) {
    for (auto& p : realUse) {
        auto [y, x] = p;
        q.push({ y,x,1 });
        visit.insert(y * N + x);
    }
    int maxTime = 0;
    while (!q.empty()) {
        auto [i, j, curTime] = q.front(); q.pop();
        maxTime = max(maxTime, curTime);
        for (int k = 0; k < 4; k++) {
            int dx = dxArr[k];
            int dy = dyArr[k];
            int ny = dy + i;
            int nx = dx + j;
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (v[ny][nx] == -1) continue; // 벽은 아예 제외
            if (visit.contains(ny * N + nx)) continue; // 다음 활성 대상자 -> 넘기기
            // 바이러스가 아닌 경우 -> 빈칸
            if (!virusIndex.contains(ny * N + nx)) leftBlankCnt -= 1;
            q.push({ ny,nx,curTime + 1 });
            visit.insert(ny * N + nx);
        }
        if (leftBlankCnt == 0)  break; // 다 했으면 다음 큐로 갈 필요 없음
    }
    if (leftBlankCnt == 0) return maxTime;
    if (leftBlankCnt < 0) throw "err";

    // 여기까지오면 실패
    return MAX_VAL;
}

void clearSection(vector<vector<int>>& v, vector<pair<int, int>>& virusYx) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (v[i][j] == -1) continue;
            if (v[i][j] == 0) continue;
            if (v[i][j] >= 1) v[i][j] = 0;
        }
    }
     //바이러스 다시 만들기
    for (size_t i = 0; i < virusYx.size(); i++) {
        auto& [y, x] = virusYx[i];
        v[y][x] = 1;
    }
}

void combination(int depth, int startIndex, vector<pair<int,int>>& realUse, vector<pair<int, int>>& virusYx, vector<vector<int>>& v, unordered_set<int>& virusIndex) {
    if (depth == M) {
        //clearSection(v, virusYx);
        int answer = getBestTime(v, realUse, virusIndex);
        minAnswer = min(minAnswer, answer);
        return;
    }
    for (int i = startIndex; i < virusYx.size(); i++) {
        realUse.push_back(virusYx[i]);
        combination(depth + 1, i + 1, realUse, virusYx,v, virusIndex);
        realUse.pop_back();
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    vector<pair<int, int>> virusYx; // y,x
    unordered_set<int> virusIndexSet;
    vector<pair<int, int>> realUse; // y,x

    vector<vector<int>> v(N,vector<int>(N));
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            int tmp; cin >> tmp;
            if (tmp == 1) {
                v[i][j] = -1;
            } else {
                if (tmp == 2) {
                    virusYx.push_back({ i,j });
                    virusIndexSet.insert(i * N + j);
                }
                if (tmp == 0) {
                    BLANK_CNT++;
                }
                v[i][j] = tmp;
            }
        }
    }
    combination(0, 0, realUse, virusYx,v, virusIndexSet);
    cout << (minAnswer == MAX_VAL ? -1 : minAnswer);
}