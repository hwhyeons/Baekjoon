#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

class Node {
public:
    int idx;
    bool visited = false;
    unordered_set<int> parent_idxs;
    unordered_set<int> child_idxs; // 자식 노드 중복 가능
};

vector<Node*> nodes;

void add_zero_node(queue<Node*>& q) {
    // 부모 노드가 없는 경우 : 위상이 0인 노드
    for (Node *node: nodes) {
        if (node == nullptr) continue; // 0번 노드는 존재 X
        if (node->parent_idxs.empty() && !node->visited) {
            q.push(node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    nodes.assign(N+1,nullptr);
    for (int i = 0; i < M; ++i) {
        int cnt;
        cin >> cnt;
        int parent_idx = -1;
        for (int j = 0; j < cnt; ++j) {
            int cur;
            cin >> cur;
            if (nodes[cur] == nullptr) {
                nodes[cur] = new Node;
                nodes[cur]->idx = cur;
            }
            if (parent_idx != -1) {
                nodes[cur]->parent_idxs.insert(parent_idx);
                nodes[parent_idx]->child_idxs.insert(cur);
            }
            parent_idx = cur;
        }
    }

    queue<Node*> q;
    add_zero_node(q);
    vector<int> answers;
    while (!q.empty()) {
        Node* cur_node = q.front(); q.pop();
        if (cur_node->visited) continue;
        cur_node->visited = true;
        unordered_set<int>& childs = cur_node->child_idxs;
        for (int child: childs) {
            Node* c = nodes.at(child);
            c->parent_idxs.erase(cur_node->idx);
            if (c->parent_idxs.empty()) { // 위상이 0인 경우
                q.push(c);
            }
        }
        answers.push_back(cur_node->idx);
    }

    // 큐가 비었는데 내용물 있는 경우 : 불가능한 경우
    for (int i = 1; i <= N; ++i) {
        Node* node = nodes.at(i);
        if (node == nullptr) continue;
        if (!node->parent_idxs.empty()) {
            cout << 0;
            return 0;
        }
    }

    for (auto k: answers) {
        cout << k << "\n";
    }

    // 담당 PD가 배정되지 않은 경우 >> 맨 마지막에 전부 출력
    for (int i = 1; i <= N; ++i) {
        Node* node = nodes.at(i);
        if (node == nullptr) {
            cout << i << "\n";
        }
    }

}