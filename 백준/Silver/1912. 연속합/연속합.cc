#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<ll> dp(n);
    dp[0] = v[0];
    for (int i = 1; i < dp.size(); ++i) {
        dp[i] = max(dp[i-1]+v[i],v[i]);
    }
    cout << *max_element(dp.begin(), dp.end());

}