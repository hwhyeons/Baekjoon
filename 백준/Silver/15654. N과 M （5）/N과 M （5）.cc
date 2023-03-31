#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

void dfs(vector<int>& v,vector<int>& out, vector<bool>& visit,int n, int r, int depth, int idx) {
    if (depth == r) {
        for (int k: out) {
            cout << k << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (visit[i]) continue;
        visit[i] = true;
        out[depth] = v[i];
        dfs(v,out,visit,n,r,depth+1,i);
        visit[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ranges::sort(v);
    vector<bool> visit(n);
    vector<int> out(r);
    dfs(v,out,visit,n,r,0,1);

}

