#include <bits/stdc++.h>
#include <ranges>

typedef long long ll ;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<ll> v(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        ll gap = v[n-1]-v[n];
        int ans = 1;
        for (int i = n-2; i >= 1; --i) {
            ll ngap = v[i]-v[i+1];
            if (ngap != gap) {
                ans = i+1;
                break;
            }
        }
        cout << ans << "\n";
    }
}