using namespace std;
#include <bits/stdc++.h>

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (auto& p : v) cin >> p.first >> p.second;
    sort(v.begin(),v.end());
    auto [curStart, maxEnd] = v[0];
    int acc = 0;
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
    cout << acc + maxEnd - curStart;
}