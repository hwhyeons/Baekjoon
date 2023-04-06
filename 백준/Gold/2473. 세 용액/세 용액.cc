#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

ll absl(ll value) {
    if (value < 0){
        return -value;
    } else {
        return value;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ranges::sort(v);
    int i1,i2,i3;
    ll ans = LLONG_MAX;
    ll ans1,ans2,ans3;
    for (int f = 0; f <= v.size()-3; ++f) {
        int s = f+1;
        int e = v.size()-1;
        ll vf = v.at(f);
        while (s < e) {
            ll vs = v.at(s);
            ll ve = v.at(e);
            ll acc = vs+ve+vf;
            if (acc == 0 ){
                cout << vf << " " << vs << " " << ve;
                exit(0);
            }
            if (absl(acc) < ans) {
                ans = absl(acc);
                ans1 = vf;
                ans2 = vs;
                ans3 = ve;
            }
            if (acc < 0 ) {
                s++;
            } else if (acc > 0) {
                e--;
            }
        }
    }
    cout << ans1 << " " << ans2 << " " << ans3;
}