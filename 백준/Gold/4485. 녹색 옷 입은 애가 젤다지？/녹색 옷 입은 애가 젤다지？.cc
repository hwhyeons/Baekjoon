// #pragma optimize("", off)
#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>

typedef long long ll;
using namespace std;

int dxarr[] = { -1,1,0,0 };
int dyarr[] = { 0, 0, 1,-1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int curTcnt = 0;
    while (1) {
        curTcnt++;
        int N;
        cin >> N;
        if (N == 0) break;
        vector<vector<int>> v(N,vector<int>(N));
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                cin >> v[i][j];
            }
        }

        // 다익스트라
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int, int>>> pq; // {가중치,넘버}
        pq.push({v[0][0],0});
        // 주의 : dist는 0번 인덱스 기준으로 설정된 배열
        vector<vector<int>> dist(N, vector<int>(N,1000000));
        dist[0][0] = v[0][0];
        unordered_set<bool> visit;
        while (!pq.empty()) {
            auto& [weight,number] = pq.top(); // number : 거쳐갈 노드
            int y = number/N;
            int x = number%N;
            pq.pop();
            for (int idx = 0; idx < 4; idx++) {
                int dx = dxarr[idx];
                int dy = dyarr[idx];
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                int newNumber = ny * N + nx; // 인접노드 인덱스
                if (dist[y][x] + v[ny][nx] < dist[ny][nx]) {
                    dist[ny][nx] = dist[y][x] + v[ny][nx];
                    pq.push({ dist[ny][nx],newNumber });
                }
            }
        }
        cout << "Problem " << curTcnt << ": " << dist.back().back() << "\n";
    }

}