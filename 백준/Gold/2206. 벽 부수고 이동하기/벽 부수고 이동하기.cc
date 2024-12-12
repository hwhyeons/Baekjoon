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


int N, M;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

class Element {
public:
    int y;
    int x;
    bool useCrash;
    int accDist;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    vector<vector<vector<bool>>> visit(N, vector<vector<bool>>(M, vector<bool>(2)));
    int test[50][50][2500];
    //vector<vector<bool>> visit(N, vector<bool>(M));
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            char c; cin >> c;
            v[i][j] = c == '0' ? 0 : 1;
        }
    }
    int NO_ANSWER = 1000000000;
    queue<Element> q;
    visit[0][0][0] = true;
    //visit[0][0] = true;
    q.push({ 0,0,false,1 });
    int minAnswer = NO_ANSWER;
    while (!q.empty()) {
        Element top = q.front();
        q.pop();
        auto [y, x, useCrash, accDist] = top;
        if (y == N - 1 && x == M - 1) {
            minAnswer = min(minAnswer, accDist);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            int boolNum = useCrash ? 1 : 0;
            if (visit[ny][nx][boolNum]) continue;
            //if (visit[ny][nx]) continue;
            if (v[ny][nx] == 1 && !useCrash) { // 벽이면서 동시에 아직 부술 기회 남은 경우
                visit[ny][nx][boolNum] = true;
                //visit[ny][nx] = true;
                q.push({ ny,nx,true,accDist + 1 });
                continue;
            } else if (v[ny][nx] == 1) {
                continue;
            }
            // assert v[ny][nx] == 0
            visit[ny][nx][boolNum] = true;
            //visit[ny][nx] = true;
            q.push({ ny,nx,useCrash,accDist + 1 });
        }
    }

    // minAnswer이 1000000000이면 - 1출력;
    if (minAnswer == NO_ANSWER) {
        cout << -1;
    } else {
        cout << minAnswer;
    }

}