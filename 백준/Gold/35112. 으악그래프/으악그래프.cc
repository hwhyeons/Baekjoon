#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
typedef long double ld;
using namespace std;



int cycleCount = 0;

int findParent(vector<int>& parents,int nodeNum) {
    if (parents[nodeNum] == nodeNum) return nodeNum;
    return parents[nodeNum] = findParent(parents,parents[nodeNum]);
}

void merge(vector<int>& parents, int node1, int node2) {
    assert(node1!=node2);
    // cout << node1 << "과 " << node2 <<" 병합\n";
    int parent1 = findParent(parents,node1);
    int parent2 = findParent(parents,node2);

    // 순환 개수+1
    if (parent1==parent2) {
        // cout << "cycleCount++\n";
        cycleCount++;
    }

    // 규칙 : 번호가 낮을 수록 더 부모쪽으로
    if (parent1 < parent2) {
        parents[parent2] = parent1;
    } else {
        parents[parent1] = parent2;
    }

    // for (int i =1;i<parents.size();i++) {
    //     cout << parents[i] << " ";
    // }
    // cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> edges; // (u,v). u->v랑 v->u 중에 하나만 추가해도 됨
    for (int i=0;i<M;i++) {
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    // 유니온 파인드는 간선을 추가할 때 어느 간선 순서로 하든 상관 없음
    vector<int> parents(N+1);
    iota(parents.begin(), parents.end(),0);

    for (auto edge : edges) {
        auto [u,v] = edge;
        merge(parents,u,v);
    }
    if (cycleCount >= 2) {
        cout << "No";
    } else {
        cout << "Yes";
    }

}