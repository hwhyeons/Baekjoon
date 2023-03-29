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
        unordered_set<int> s1;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            s1.insert(tmp);
        }
        int m; cin >> m;
        for (int i = 0; i < m; ++i) {
            int t; cin>>t;
            if (s1.contains(t)) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }



}
