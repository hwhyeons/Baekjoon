#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcnt;
    cin >> tcnt;
    while (tcnt--) {
        int n,m,c;
        cin >> n >> m >> c;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int ans = 0;
        for (int i = 0; i <= n-m; ++i) {
            auto [min,max] = minmax_element(v.begin()+i, v.begin()+i+m);
            if ((*max-*min) <= c) ans++;
        }
        cout << ans << "\n";
    }


}