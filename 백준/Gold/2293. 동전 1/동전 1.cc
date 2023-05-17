#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    vector<int> dp(k+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dp.front() = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = v.at(i); j <= k; j++) {
            dp[j] = dp[j] + dp[j-v.at(i)];
        }
    }
    cout << dp.back();
}