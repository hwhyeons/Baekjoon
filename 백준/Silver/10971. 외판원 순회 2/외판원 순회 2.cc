
#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<ll>> w(n,vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w[i][j];
        }
    }

    vector<int> per(n);
    iota(per.begin(), per.end(),0);
    ll mn = LLONG_MAX;
    do {
        ll ans = 0;
        for (int i = 0; i < n-1; ++i) {
            ll we = w[per[i]][per[i + 1]];
            if (we == 0) goto re;
            ans += we;
        }
        if (w[per.back()][per.front()] == 0) {
            goto re;
        }
        ans += w[per.back()][per.front()];
        mn = min(ans, mn);
        re:
        cout << "";
    } while (next_permutation(per.begin(), per.end()));
    cout << mn;

}