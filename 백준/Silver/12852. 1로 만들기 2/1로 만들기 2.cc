
#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {cout << 0 << "\n" << 1; return 0;};
    vector<pair<int,int>> dp(n+1,{n+10,-1}); // {count / beforeIndex}
    dp[n].first = 0;
    for (int i = n; i >= 1; --i) {
        int cur = dp[i].first;
        if (cur+1 < dp[i-1].first) {
            dp[i-1].first = cur+1;
            dp[i-1].second = i;
        }
        if (i%2 == 0 && cur+1 < dp[i/2].first) {
            dp[i/2].first = cur+1;
            dp[i/2].second = i;
        }
        if (i%3 == 0 && cur+1 < dp[i/3].first) {
            dp[i/3].first = cur+1;
            dp[i/3].second = i;
        }
    }

    // trace path
    int cur_idx = 1;
    vector<int> ans;
    while (true) {
        ans.push_back(cur_idx);
        int next_idx = dp[cur_idx].second;
        if (next_idx == -1) break;
        cur_idx = next_idx;
    }
    cout << dp[1].first << "\n";
    for (auto it = ans.rbegin(); it!=ans.rend(); it++) {
        cout << *it << " ";
    }
}