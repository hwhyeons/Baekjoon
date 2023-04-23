#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

class Node {
public:
    int idx;
    bool visited = false;
    int before_time_max = 0; // 이전 일 끝내는데 걸리는 최대 시간
    int do_time = 0;
    unordered_set<int> parent_idxs;
    unordered_set<int> child_idxs; // 자식 노드 중복 가능
};

vector<Node*> nodes;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    nodes.assign(N+1,nullptr);
    for (int i = 1; i <= N; ++i) {
        nodes[i] = new Node;
        nodes[i]->idx = i;
    }
    for (int i = 1; i <= N; ++i) {
        int time;
        cin >> time;
        nodes[i]->do_time = time;
        while (true) {
            int tmp;
            cin >> tmp;
            if (tmp == -1) break;
            // i : 건물번호

            nodes[i]->parent_idxs.insert(tmp);
            nodes[tmp]->child_idxs.insert(i);
        }
    }


    // 시작 노드 추가
    queue<int> q;
    for (int j = 1; j <= N; ++j) {
        if (nodes[j]->parent_idxs.empty()) {
            q.push(j);
        }
    }

    while (!q.empty()) {
        Node* cur_node = nodes.at(q.front()); q.pop();
        int cur_node_time = cur_node->do_time;
        int cur_acc_time = cur_node->before_time_max;
        for (int child_idx: cur_node->child_idxs) {
            Node *child = nodes.at(child_idx);
            child->before_time_max = max(child->before_time_max,cur_acc_time+cur_node_time);
            child->parent_idxs.erase(cur_node->idx);
            if (child->parent_idxs.empty()) {
                q.push(child_idx);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << nodes.at(i)->before_time_max + nodes.at(i)->do_time << "\n";
    }


}