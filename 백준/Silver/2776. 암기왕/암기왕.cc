#include <bits/stdc++.h>
#include <ranges>

#define ll long long
#define inf INT_MAX
#define rv ranges::views

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t_cnt; cin>>t_cnt;
    while (t_cnt--) {
        int n; cin >> n;
        vector<int> v1;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            v1.emplace_back(tmp);
        }
        ranges::sort(v1);
        int m; cin >> m;
        for (int i = 0; i < m; ++i) {
            int t; cin>>t;
            if (ranges::binary_search(v1,t)) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }



}
