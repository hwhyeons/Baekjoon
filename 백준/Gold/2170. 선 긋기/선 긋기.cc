using namespace std;
#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for (auto& p : v) cin >> p.first >> p.second;
    sort(v.begin(),v.end());
    auto [curStart, maxEnd] = v[0];
    ll acc = 0ll;
    for (auto& p : v) {
        auto& [s,e] = p;
        if (s <= maxEnd) {
            maxEnd = max(maxEnd,e);
        } else {
            acc += maxEnd - curStart;
            curStart = s;
            maxEnd = e;
        }
    }
    acc += maxEnd - curStart;
    cout << acc;
}