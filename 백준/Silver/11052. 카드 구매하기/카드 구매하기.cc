#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,t;
    cin >> n;
    vector<int> dp(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        dp[i] = t;
        for (int j = 1; j < i; ++j) {
            dp[i] = max(dp[i],dp[i-j]+dp[j]);
        }
    }
    cout << dp[n];
}