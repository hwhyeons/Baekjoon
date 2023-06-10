#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

class Node {
public:
    int pIdx;
    int depth;
    vector<int> conn;
    bool v1 = false;
};


vector<Node*> nodes;
int getCommonParent(int a, int b) {
    if (a==b) return a;
    Node* n1 = nodes.at(a);
    Node* n2 = nodes.at(b);
    int d1 = n1->depth;
    int d2 = n2->depth;
    if (d1 == d2) {
        int p1 = n1->pIdx;
        int p2 = n2->pIdx;
        if (p1 == p2) {
            return p1;
        } else {
            return getCommonParent(p1,p2);
        }
    } else { // diff depth
        if (d1 < d2) {
            int p2 = n2->pIdx;
            return getCommonParent(a,p2);
        } else {
            int p1 = n1->pIdx;
            return getCommonParent(p1,b);
        }
    }
}

// set nodes depth
void dfs(int curNodeIndex) {
    auto& cons = nodes.at(curNodeIndex)->conn;
    int curDepth = nodes.at(curNodeIndex)->depth;
    for (int cIdx: cons) {
        Node* child = nodes.at(cIdx);
        if (child->v1) continue;
        child->depth = curDepth+1;
        child->v1 = true;
        child->pIdx = curNodeIndex;
        dfs(cIdx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    nodes.assign(n + 1, nullptr);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        cin >> a >> b;
        if (nodes[a] == nullptr) nodes[a] = new Node();
        nodes[a]->conn.push_back(b);
        if (nodes[b] == nullptr) nodes[b] = new Node();
        nodes[b]->conn.push_back(a);
    }

    // 깊이 계산
    nodes[1]->depth = 0;
    nodes[1]->v1 = true;
    nodes[1]->pIdx = -1;
    dfs(1);


    // 테스트 케이스
    int tcnt;
    cin >> tcnt;
    for (int i = 0; i < tcnt; ++i) {
        int a,b;
        cin >> a >> b;
        cout << getCommonParent(a,b) << "\n";
    }

}