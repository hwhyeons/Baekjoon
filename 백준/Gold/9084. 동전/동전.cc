#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t_cnt; cin >> t_cnt;
    while (t_cnt--) {
        int n;
        cin >> n;
        vector<int> coins(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> coins[i];
        }
        int want_money;
        cin >> want_money;
        vector<vector<int>> dp(want_money+1,vector<int>(n+1));

        int min_coin = coins.at(1);
        dp[min_coin][1] = 1;
        for (int i = min_coin; i <= want_money; ++i) {
            // k == 1일 떄는 배수일 때만 해당
            if (i%min_coin == 0) {
                dp[i][1] = 1;
            }
            for (int k = 2; k <= n; ++k) {
                if (i-coins[k] == 0) {
                    dp[i][k] = dp[i][k-1]+1;
                } else if (i-coins[k] > 0) {
                    dp[i][k] = dp[i][k-1]+dp[i-coins[k]][k];
                } else {
                    dp[i][k] = dp[i][k-1];
                }
            }
        }
        cout << dp[want_money].back()  << "\n";
    }


}