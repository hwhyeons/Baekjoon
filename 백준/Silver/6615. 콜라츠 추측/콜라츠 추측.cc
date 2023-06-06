
#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b;
    while (true) {
        cin >> a >> b;
        if (a+b==0) break;
        unordered_map<ll,ll> va;
        unordered_map<ll,ll> vb;
        ll s = a;
        ll ans1;
        ll idx = 0;
        while (true) {
            if (s == 1) {
                va[1] = idx;
                break;
            } else if (va.contains(s)) {
                break;
            } else {
                va[s] = idx;
            }
            s = s%2 ? 3*s+1 : s/2;
            idx++;
        }

        s = b;
        idx = 0;
        ll ans2;
        ll ans3;
        while (true) {
            if (va.contains(s)) {
                ans2 = idx;
                ans1 = va[s];
                ans3 = s;
                break;
            }
            s = s%2 ? 3*s+1 : s/2;
            idx++;
        }
        cout << a << " needs " << ans1 << " steps, " << b << " needs " << ans2 << " steps, they meet at " << ans3 << "\n";
    }
}