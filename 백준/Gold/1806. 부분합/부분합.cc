
#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    int n,S;
    cin >> n >> S;
    vector<ll> v(n+1);
    v[0] = 0;
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        ll tmp; cin >> tmp;
        v[i] = v[i-1] + tmp;
    }

    int s = 1;
    int e = 1;
    while (s<=e && e<=n) {
        int len = e-s+1;
        ll acc = v[e]-v[s-1];
        if (acc >= S) {
            ans = min(ans,len);
            s++;
        } else {
            e++;
        }
    }

    if (ans == INT_MAX) {
        cout << 0;
    } else {
        cout << ans;
    }

}