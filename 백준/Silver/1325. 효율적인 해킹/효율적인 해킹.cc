#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int dfs(vector<vector<int>>& nodes, auto& vst, int idx, int start){
    vst[idx] = start;
    int acc = 1;
    for (int fidx : nodes.at(idx)) {
        if (vst[fidx] == start) continue;
        acc += dfs(nodes,vst,fidx,start);
    }
    return acc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> nodes(n+1);
    vector<int> vst(n+1);
    for (int i = 0; i < m; ++i) {
        int t1,t2;
        cin >> t1 >> t2;
        auto& vec = nodes.at(t2);
        vec.push_back(t1);
    }
    vector<int> answer;
    int mx = -1;
    for (int i = 1; i <= n; ++i) {
        int ansTmp = dfs(nodes,vst,i,i);
        if (ansTmp > mx) {
            mx = ansTmp;
            answer.clear();
            answer.push_back(i);
        } else if (ansTmp == mx) {
            answer.push_back(i);
        }
    }

    ranges::sort(answer);
    ranges::copy(answer,ostream_iterator<int>(cout," "));

}