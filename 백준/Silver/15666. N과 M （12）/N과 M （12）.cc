#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

unordered_set<string> se;
void dfs(vector<int>& v,vector<int>& out, vector<bool>& visit,int n, int r, int depth, int idx) {
    if (depth == r) {
        string s;
        for (int k: out) {
            s.append(to_string(k)+" ");
        }
        if (se.contains(s)) return;
        cout << s << "\n";
        se.insert(s);
        return;
    }
    for (int i = idx; i < n; ++i) {
//        if (visit[i]) continue;
//        visit[i] = true;
        out[depth] = v[i];
        dfs(v,out,visit,n,r,depth+1,i);
//        visit[i] = false;
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
    v.erase(unique(v.begin(),v.end()),v.end());
    vector<bool> visit(v.size());
    vector<int> out(r);
    dfs(v,out,visit,v.size(),r,0,0);

}

