#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

// 도미노
class Node {
public:
    vector<int> fr;
    vector<int> pr;
    bool visit = false;
    int parent; // 조상이 아니라 바로 직계 부모인듯?
    bool scc_ok = false;
};
int id = 1;

int dfs(vector<vector<int>>& all_scc,vector<Node>& nodes,stack<int>& stk, int idx) {
    stk.push(idx);
    Node& cur_node = nodes.at(idx);
    cur_node.parent = id++;
    cur_node.visit = true;
    int parent = cur_node.parent;
    for (int fidx: cur_node.fr) {
        Node &frnode = nodes.at(fidx);
        // 친구 노드가 이미 방문된 노드
        if (!frnode.visit) {
            parent = min(parent,dfs(all_scc,nodes,stk,fidx));
        } else if (!frnode.scc_ok) { // SCC가 결정되지 않은 경우
            parent = min(parent,frnode.parent);
        }
    }

    if (parent == cur_node.parent) {
        vector<int> scc;
        while (true) {
            int t = stk.top(); stk.pop();
            scc.push_back(t);
            nodes.at(t).scc_ok = true;
            if (t == idx) break;
        }
        all_scc.push_back(scc);
    }
    return parent;
}

void cascade(vector<Node>& nodes,vector<bool> &vst2, int idx) {
    Node& node = nodes.at(idx);
    vst2[idx] = true;
    auto& frs = node.fr;
    for (int fridx: frs) {
        if (vst2[fridx]) continue;
        else {
            vst2[fridx] = true;
            cascade(nodes,vst2,fridx);
        }
    }
}

// 부모 노드 전파 및 찾기
void dfs2(vector<Node>& nodes,vector<bool>& all_vst,vector<bool>& vst2,vector<int>& scc_number, int idx) {
    Node &node = nodes.at(idx);
    all_vst.at(idx) = true;
    auto& prs = node.pr;
    for (int pridx: prs) {
        if (all_vst[pridx]) continue;
        else {
            // 만약에 같은 집합이면 어차피 전파될 때 처리되므로
            if (scc_number[idx] == scc_number[pridx]) {
                all_vst[pridx] = true;
                dfs2(nodes,all_vst,vst2,scc_number,pridx);
                continue;
            } else {
                all_vst[pridx] = true;
                dfs2(nodes,all_vst,vst2,scc_number,pridx);
                break;
            }
        }
    }
    cascade(nodes,vst2, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcnt;
    cin >> tcnt;
    while (tcnt--) {
        vector<Node> nodes;
        vector<vector<int>> all_scc;

        int n,m;
        cin >> n >> m;
        id = 1;
        nodes.assign(n+1,Node());
        stack<int> stk;
        for (int i = 0; i < m; ++i) {
            int t1,t2;
            cin >> t1 >> t2;
            nodes.at(t1).fr.push_back(t2);
            nodes.at(t2).pr.push_back(t1);
        }

        // cal
        for (int i = 1; i <= n; ++i) {
            if (nodes.at(i).visit) continue;
            dfs(all_scc,nodes,stk,i);
        }

        vector<int> scc_number(n+1);
        for (int i = 0; i < all_scc.size(); ++i) {
            int group_num = i;
            auto& vec = all_scc.at(i);
            for (auto k : vec) {
                scc_number[k] = group_num;
            }
        }

        // 안으로 들어오는 화살표가 없는 경우
        int answer = 0;
        for (auto &scc: all_scc) {
            // scc에 속한 모든 노드에서 안쪽 화살표가 있는지 확인 -> 모든 parent.size()가 0인 경우
            for (int idx : scc) {
                auto& prs = nodes.at(idx).pr;
                for (int pridx : prs) {
                    if (scc_number[pridx] == scc_number[idx]) continue;
                    else { // 그룹 다른게 하나라도 있는 경우 정답이 될 수 없음
                        goto out;
                    }
                }
            }
            answer++;
            out:
            continue;
        }
        cout << answer << "\n";
    }
}