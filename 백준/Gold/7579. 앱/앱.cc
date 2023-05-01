#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<ll> mem(n+1);
    vector<ll> cost(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> mem[i];
    }
    ll allCostSum = 0ll;
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
        allCostSum+=cost[i];
    }

    vector<vector<ll>> dp(allCostSum+1,vector<ll>(n+1));
    vector<vector<ll>> weight(allCostSum+1,vector<ll>(n+1));
    // 행 : 최대 비용
    // 열 : 앱
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 1; j < dp[i].size(); ++j) {
            // 무게 자체가 최대 용량으로는 불가능한 경우
            if (cost.at(j) > i) {
                if (i >= 1) {
                    if (dp[i][j-1] > dp[i-1][j]) {
                        dp[i][j] = dp[i][j-1];
                        weight[i][j] = weight[i][j-1];
                    } else if (dp[i][j-1] < dp[i-1][j]) {
                        dp[i][j] = dp[i-1][j];
                        weight[i][j] = weight[i-1][j];
                    } else { // 동일 할 때
                        dp[i][j] = dp[i][j-1];
                        weight[i][j] = min(weight[i][j-1],weight[i-1][j]);
                    }
                } else {
                    dp[i][j] = dp[i][j-1];
                    weight[i][j] = weight[i][j-1];
                }
                continue;
            }

            // 가능은 할 때
            ll beforeWeight = weight[i][j-1];
            if (beforeWeight+cost[j] <= i) { // 아예 공간이 남는 경우
                weight[i][j] = beforeWeight + cost[j];
                dp[i][j] = dp[i][j-1] + mem[j];
            } else {
                // 바로 공간이 남지는 않는 경우 -> "최대박스무게"에서 현재 무게 빼서 계산
                int cmpRow = i - cost[j];
                // t1이번꺼 선택하는 경우
                ll t1 = dp[cmpRow][j-1] + mem[j];
                ll t2;
                ll w1 = weight[cmpRow][j-1] + cost[j];
                ll w2;
                if (i>=1) {
                    // t2 : 이번 앱 선택 안하는 경우
                    if (dp[i][j-1] == dp[i-1][j]) {
                        t2 = dp[i][j-1];
                        w2 = min(weight[i][j-1],weight[i-1][j]);
                    } else {
                        t2 = max(dp[i][j-1],dp[i-1][j]);
                        w2 = t2 == dp[i][j-1] ? weight[i][j-1] : weight[i-1][j];
                    }
                } else {
                    t2 = dp[i][j-1];
                    w2 = weight[i][j-1];
                }
                if (t1 > t2) {
                    dp[i][j] = t1;
                    weight[i][j] = w1;
                } else if (t2 > t1) {
                    dp[i][j] = t2;
                    weight[i][j] = w2;
                } else { // t1 == t2
                    dp[i][j] = t1;
                    weight[i][j] = min(w1,w2);
                }
            }
        }
    }

    ll mn = LLONG_MAX;
    // 비용이 조건을 만족하면서, 소모 가중치는 가장 적은 경우
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 1; j < dp[i].size(); ++j) {
            if (dp[i][j] >= m) {
                mn = min(mn,weight[i][j]);
            }
        }
    }
    cout << mn;
}