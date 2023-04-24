#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

class Node {
public:
    unordered_set<int> childs;
    unordered_set<int> pr;
    bool visited = false;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    vector<Node> all_node(N+1);
//    all_node.assign(N+1,Node());
    for (int i = 0; i < M; ++i) {
        int t1,t2;
        cin >> t1 >> t2;
        all_node.at(t1).pr.insert(t2);
        all_node.at(t2).childs.insert(t1);
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        // 진입차수 0인 노드 추가
        if (all_node.at(i).childs.empty()) {
            q.push(i);
        }
    }
    vector<int> answer;
    while (!q.empty()) {
        int idx = q.front(); q.pop();
        Node& node = all_node[idx];
        if (node.visited) continue;
        node.visited = true;
        for (int pr_idx: node.pr) {
            Node &child_node = all_node[pr_idx];
            child_node.childs.erase(idx);
            if (child_node.childs.empty()) {
                q.push(pr_idx);
            }
        }
        answer.push_back(idx);
    }

    for_each(answer.begin(), answer.end(),[](int idx){
        cout << idx << " ";
    });

    for (int i = 1; i <= N; ++i) {
        if (!all_node[i].visited) {
            cout << i << " ";
        }
    }




}