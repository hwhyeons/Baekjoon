#include <bits/stdc++.h>
#include <ranges>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t_cnt; cin >> t_cnt;
    while (t_cnt--) {
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; ++i) {
            int t1,t2; cin>>t1>>t2;
            v[i] = {t1,t2};
        }
        ranges::sort(v);
        int ans = v.size();
        int sec = v[0].second;
        for (int j = 1; j < n; ++j) {
            auto p2 = v[j];
            if (p2.second > sec) {
                ans--;
            } else {
                sec = p2.second;
            }
        }
        cout << ans << "\n";
    }
}

