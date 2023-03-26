#include <algorithm>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <limits.h>
#include <iostream>
#include <string>

using namespace std;
#define ll long long


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> is_best(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        int before = v[i];
        for (int j = i+1; j <= n; ++j) {
            int gap = abs(v[j] - before);
            if (gap == 0) is_best[i][j] = 1;
            else is_best[i][j] = 0;
            before = gap;
        }
    }

    vector<int> dp(n+1);
    dp[1] = 1; // 첫번째 원소만 봤을 때 가장 최선의 방법은 한가지
    dp[2] = is_best[1][2] == 1 ? 1 : 2; // 1~2번째 원소만 봤을 때 최소는, 1~2번째를 한번에 집을 수 있으면 1번, 그게 아니면 2번
    for (int idx = 3; idx <= n; ++idx) {
        int mn1 = dp[idx-1]+1; // idx-1번 까지 최소로 뽑고, idx번째는 조약돌 한번에 뽑기 (문제에서는 작업2)
        int mn2 = INT_MAX;
        for (int i = 1; i < idx; ++i) {
            if (is_best[i][idx] == 1) {
                mn2 = min(mn2,idx-i + dp[i-1]);
            }
        }
        dp[idx] = min(mn1,mn2);
    }
    cout << dp[n];
}
