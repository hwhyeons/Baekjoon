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

ll INF = 2100000000LL;
int V, E;

class Edge {
public:
    int end;
    int weight;
};

class Node {
public:
    int num; // node number
    ll weight;

    bool operator<(const Node& rhs) const {
        return this->weight > rhs.weight; // pq이므로 오름차순
    }
};

void dik(int startPoint, vector<vector<Edge>>& edges) {
    priority_queue<Node> pq;
    vector<ll> answer(V + 1, INF); // "출발점"을 기준으로 하는 거리 배열
    answer[startPoint] = 0;

    pq.push({ startPoint,0 });
    while (!pq.empty()) {
        Node node = pq.top(); pq.pop();
        for (Edge nb : edges[node.num]) {
            // nb : 자신과 연결된 간선
            if (node.weight + nb.weight < answer[nb.end]) {
                answer[nb.end] = node.weight + nb.weight;
                pq.push({nb.end, answer[nb.end]});
            }
        }
    }


    // 값 출력
    for (int i = 1; i < answer.size(); i++) {
        if (answer[i] == INF) {
            cout << "INF" << "\n";
        } else {
            cout << answer[i] << "\n";
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    int startPoint;
    cin >> startPoint;
    vector<vector<Edge>> edges(V + 1, vector<Edge>());

    for (size_t i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({ v,w });
    }
    dik(startPoint, edges);

}
