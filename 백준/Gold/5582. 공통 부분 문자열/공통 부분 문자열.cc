#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2;
    cin >> s1 >> s2;
    int mx = 0;
    vector<vector<int>> dp(s2.size()+1,vector<int>(s1.size()+1));
    for (int row = 1; row < dp.size(); ++row) {
        for (int col = 1; col < dp[0].size(); ++col) {
            if (s1[col-1] == s2[row-1]) {
                dp[row][col] = dp[row-1][col-1]+1;
                mx = max(mx,dp[row][col]);
            }
        }
    }
    cout << mx;

}