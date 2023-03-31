#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

void dfs(vector<int>& out, int n, int r, int depth, int idx) {
    if (depth == r) {
        for (int k: out) {
            cout << k << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = idx; i <= n; ++i) {
        out[depth] = i;
        dfs(out,n,r,depth+1,i+1);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
//    vector<int> v(n);
//    iota(v.begin(), v.end(), 1);
    vector<int> out(r);
    dfs(out,n,r,0,1);

}

