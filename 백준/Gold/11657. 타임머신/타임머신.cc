#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

void bellmanFord(int n, int m, auto& edges) {
    // 출발지 : 1번 노드
    vector<ll> minDist(n+1,INT_MAX);
    int snode = 1;
    minDist.at(snode) = 0; // 출발지
    for (int i = 1; i <= n; ++i) {
        for (auto &edge: edges) {
            auto& [s,e,w] = edge;
            if (minDist.at(s) == INT_MAX) continue; // 이거 안하면, "무한대 + 음수"가 만나서 갱신되는 문제가 발생
//            if (s != i) continue; -> 해당 노드에서 해당 노드출발하는 엣지만 따지는 것이 아니라, 모든 간선을 다 따져야함
            if (minDist.at(s) + w < minDist.at(e)) {
                minDist.at(e) = minDist.at(s) + w;
            }
        }
    }

    // 음의 사이클 확인
    for (auto &edge: edges) {
        auto& [s,e,w] = edge;
        if (minDist.at(s) == INT_MAX) continue;
        if (minDist.at(s) + w < minDist.at(e)) {
            cout << "-1";
            return;
        }
    }
    
    // 출발지 노드는 출력안하므로 1번은 스킵
    for (int i = 2; i <= n; ++i) {
        cout << ((minDist.at(i) == INT_MAX) ? -1 : minDist.at(i)) << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<tuple<int,int,ll>> edges; // (시작점 / 끝점 / 가중치)

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a,b; ll c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    bellmanFord(n,m,edges);

}