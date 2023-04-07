#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0; return 0;
    }
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int sidx = 0;
    int cidx = 1;
    int ans = 0;
    while (true) {
        if (cidx == n) break;
        if (v.at(cidx) > v.at(cidx-1)) {
            ans = max(ans,v.at(cidx) - v.at(sidx));
        } else {
            sidx = cidx;
        }
        cidx++;
    }
    cout << ans;
}