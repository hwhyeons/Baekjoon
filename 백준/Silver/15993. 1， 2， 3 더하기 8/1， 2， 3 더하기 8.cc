#include <bits/stdc++.h>
#include <ranges>

typedef long long ll ;

using namespace std;

ll divide = 1000000009ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ll>> dp(100001,vector<ll>(2)); // 홀 -> 짝
    dp[1][0] = 1; // 홀
    dp[1][1] = 0; // 짝
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 2;
    dp[3][1] = 2;
    for (int i = 4; i <= 100000; ++i) {
        dp[i][0] = ((dp[i-1][1]+dp[i-2][1])%divide+dp[i-3][1])%divide;
        dp[i][1] = ((dp[i-1][0]+dp[i-2][0])%divide+dp[i-3][0])%divide;
    }
    int t_cnt; cin >> t_cnt;
    for (int i = 0; i < t_cnt; ++i) {
        int tmp;
        cin >> tmp;
        cout << dp[tmp][0] << " " << dp[tmp][1];
        cout << "\n";
    }
}