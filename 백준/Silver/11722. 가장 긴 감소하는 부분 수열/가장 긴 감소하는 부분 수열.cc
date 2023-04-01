#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> dp(n);
    vector<int> mn(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    dp[0] = 1;
    mn[0] = v[0];
    for (int i = 1; i < n; ++i) {
        int dp2 = 1; // 자기 자신
        for (int j = 0; j < i; ++j) {
            if (v[j] > v[i] && dp[j] + 1 > dp2) {
                dp2 = dp[j]+1;
            }
        }
        dp[i]= dp2;
    }
    cout << *max_element(dp.begin(), dp.end());
}

