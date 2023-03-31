#include <bits/stdc++.h>
#include <ranges>

#define ll long long

using namespace std;

class node {
public:
    int idx;
    node* parent;
    vector<node*> childs;
    bool visit = false;
    node(int idx, node* parent) {
        this->idx = idx;
        this->parent = parent;
    }
};

vector<node*> v;

int remove_idx;

int dfs(node* curNode) {
    int idx = curNode->idx;
    if (idx==remove_idx) return 0;
    curNode->visit = true;
    if (curNode->childs.empty()) {
        return 1;
    }
    vector<node*> childs = curNode->childs;
    int cnt = 0;
    if (childs.size() == 1 && childs[0]->idx == remove_idx) {
        return 1;
    }
    for (auto c: childs) {
        if (c->visit) continue;
        cnt += dfs(c);
    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    v.assign(n,nullptr);
    for (int i = 0; i < n; ++i) {
        v[i] = new node(i, nullptr);
    }
    int root_idx;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == -1) {
            v[i]->parent = nullptr;
            root_idx = i;
        } else {
            v[i]->parent = v[t];
            v[t]->childs.emplace_back(v[i]);
        }
    }
    cin >> remove_idx;
    cout << dfs(v[root_idx]);
}

