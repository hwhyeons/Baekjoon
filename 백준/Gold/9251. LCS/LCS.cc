#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s2.size()+1,vector<int>(s1.size()+1));
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < dp[0].size(); ++j) {
            if (s2[i-1] == s1[j-1]) { // last same
                dp[i][j] = dp[i-1][j-1] + 1;
            } else { // different
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp.back().back();
}