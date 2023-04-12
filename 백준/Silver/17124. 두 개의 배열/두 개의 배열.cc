#include <bits/stdc++.h>
#include <ranges>

typedef long long ll ;

using namespace std;

// vb : sorted vector
ll get_min_gap_val(ll want, vector<ll>& vb) {
    ll s = 0;
    ll e = vb.size()-1;
    ll mn = LLONG_MAX;
    ll mn_idx = LLONG_MAX;
    while (s <= e) {
        ll m = (s + e) / 2;
        ll mid_val = vb.at(m);
        ll gap_n = want - mid_val;
        ll gap = abs(gap_n);
        if (gap < mn){
            mn_idx = m;
            mn = gap;
        } else if (gap == mn) {
            mn_idx = min(mn_idx,m);
        }

        if (gap_n < 0) {
            e = m-1;
        } else {
            s = m+1;
        }
    }
    return vb.at(mn_idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tcnt; cin >> tcnt;
    while (tcnt--) {
        ll acnt, bcnt;
        cin >> acnt >> bcnt;
        vector<ll> va(acnt);
        vector<ll> vb(bcnt);
        for (ll i = 0; i < acnt; ++i) {
            cin >> va[i];
        }
        for (ll i = 0; i < bcnt; ++i) {
            cin >> vb[i];
        }
        ranges::sort(vb);
        ll acc = 0;
        for (ll i = 0; i < acnt; ++i) {
            ll want = va[i];
            ll adj_min_gap = get_min_gap_val(want,vb);
            acc += adj_min_gap;
        }
        cout << acc << "\n";
    }
}