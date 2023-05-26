#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    ll mxLcm = v.front();
    for (int i = 1; i < n; ++i) {
        mxLcm = lcm(mxLcm, v[i]);
    }
    ll acc = accumulate(v.begin(), v.end(),0LL,[mxLcm](ll before, ll k){
        return before+mxLcm/k;
    });
    ll gc = gcd(mxLcm, acc);
    cout << mxLcm/gc << "/" << acc/gc;
}