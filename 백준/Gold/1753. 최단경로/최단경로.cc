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
        return rhs.weight < this->weight; // pq이므로 오름차순
    }
};

void dik(int startPoint, vector<vector<Edge>>& edges) {
    priority_queue<Node> pq;
    vector<ll> answer(V+1,INF); // "출발점"을 기준으로 하는 거리 배열
    answer[startPoint] = 0;

    pq.push({startPoint,0});
    while (!pq.empty()) {
        Node node = pq.top(); pq.pop();
        int curNode = node.num;
        int accWeight = node.weight;
        if (answer[curNode] < accWeight) continue; // 이거 없으면 시간초과

        // 인접 간선
        for (Edge ed : edges[curNode]) {
            auto [adj, w] = ed; // 간선번호, 간선 가중치
            if (accWeight +  w < answer[adj]) { // "현재노드"를 거쳐서 "인접노드"를 향해 갈 때 최소가 되는경우 갱신 및 pq에 추가
                answer[adj] = accWeight + w; // 최소 값 교체 필수!!
                pq.push({ adj , answer[adj] });
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
