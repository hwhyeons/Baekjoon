#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;

ll divide = 1000000000;

vector<ll> dp(10000001,-1);

ll f(ll num) {
    if (dp[num] != -1) {
        return dp[num]% divide;
    }
    ll ans = (((num - 1) % divide) * (f(num - 1) % divide + f(num - 2) % divide)) % divide;
    dp[num] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 9;
    dp[5] = 44;
    int want;
    cin >> want;
    cout << f(want);
}