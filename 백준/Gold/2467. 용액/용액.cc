#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int s=0,e=v.size()-1;
    ll mn = LLONG_MAX;
    ll ans1,ans2;
    while (s < e) {
        ll gap  = v[e]+v[s];
        if (abs(gap) < mn) {
            mn = abs(gap);
            ans1 = v[s];
            ans2 = v[e];
        }
        if (gap < 0) {
            s++;
        } else if (gap > 0){
            e--;
        } else {
            cout << v[s] << " " << v[e];
            return 0;
        }

    }
    cout << ans1 << " " << ans2;
}