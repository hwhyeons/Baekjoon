#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    ll mx = accumulate(v.begin(),v.begin()+m,0ll);
    ll before = mx;
    for (int i = 1; i <= n-m; ++i) {
        before -= v.at(i - 1);
        before += v.at(i+m-1);
        mx = max(mx, before);
    }
    cout << mx;
}