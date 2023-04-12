#include <bits/stdc++.h>
#include <ranges>

typedef unsigned long long ull;

using namespace std;


class Edge {
public:
    int s,e;
    ull weight;

    Edge(int s, int e, ull weight){
        if (s == 0 || e== 0 || (s==e)) throw "error";
        this->s = s;
        this->e = e;
        this->weight = weight;
    }

    bool operator<(const Edge &edge) const{
        return this->weight > edge.weight;
    }
};

vector<int> vp; // {노드 번호 / 부모}
priority_queue<Edge> pq;

int get_parent(int idx) {
    if (vp[idx] == idx) {
        return idx;
    }
    int p = vp[idx];
    return vp[idx] = get_parent(p);
}

ull acc = 0ULL;

bool merge(int p1, int p2) {
    int parent1 = get_parent(p1);
    int parent2 = get_parent(p2);
    if (parent1 == parent2) return false;
    if (parent1 < parent2) {
        vp[parent2] = parent1;
    } else {
        vp[parent1] = parent2;
    }
    return true;
}

ull max_w = 0ULL;

// 크루스칼
void krus() {
    int finished_cnt = 0;
    while (!pq.empty()) {
        Edge edge = pq.top(); pq.pop();
        int s = edge.s;
        int e = edge.e;
        ull weight = edge.weight;
        bool ok = merge(s,e);
        if (ok) {
            acc += weight;
            max_w = max(max_w,weight);
            finished_cnt++;
        }
        if (finished_cnt == vp.size()) { // 0번 인덱스 사용 안하므로 한개 더 추가
            break;
        }
    }
    cout << acc-max_w; // 최소 신장 트리에서 가장 가중치가 높은걸 끊어버린다
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    vp.assign(N+1,0);
    iota(vp.begin(), vp.end(),0); // 자기 자신이 부모

    for (int i = 0; i < M; ++i) {
        int t1,t2,t3;
        cin >> t1>>t2>>t3;
        if (t1 == t2) continue;
        Edge edge(t1,t2,t3);
        pq.push(edge);
    }
    krus();

}