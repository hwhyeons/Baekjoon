#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

class Node{
public:
    int idx;
    Node* parent;
    Node(int idx){
        this->idx =idx;
        this->parent = this;
    }
};

vector<Node*> v;


Node* find(Node* node) {
    if (node->parent == node) {
        return node;
    } else {
        return node->parent = find(node->parent);
    }
}

void merge(Node* n1, Node* n2) {
    Node* p1 = find(n1);
    Node* p2 = find(n2);
    if (p1->idx < p2->idx) {
        p2->parent = p1->parent;
    } else {
        p1->parent = p2->parent;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int G,P;
    cin >> G >> P;
    // make node
    for (int i = 0; i <= G; ++i) {
        Node* ntmp = new Node(i);
        v.emplace_back(ntmp);
    }

    int ans = 0;
    for (int i = 0; i < P; ++i) {
        int t;
        cin >> t;
        Node* cur = v[t];
        Node* parent = find(cur);
        if (parent->idx == 0) { // 0번 노드가 조상 >> 더이상 게이트에 넣을 수 없음
            break;
        }
        merge(parent,v[parent->idx-1]); // 현재 노드와 직전 노드 병합
        ans++;
    }

    cout << ans;
    
}
