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
    int N,K; cin >> N >> K;
    vector<int> weight(N+1);
    vector<int> value(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> weight[i];
        cin >> value[i];
    }
    vector<vector<int>> dp(K+1,vector<int>(N+1));
    vector<vector<int>> dp_weight(K+1,vector<int>(N+1));
    for (int i = 1; i <= K; ++i) { // 행
        // i = 현재 최고로 담을 수 있는 무게
        for (int j = 1; j <= N; ++j) { // 열
            int cur_w = weight[j];
            int cur_val = value[j];
            if (cur_w > i) { // 배낭 최대 한도보다 높아서 아예 넣을 수 없는 경우
                dp[i][j] = dp[i][j-1]; // 바로 왼쪽 것이 무조건 최적
                dp_weight[i][j] = dp_weight[i][j-1];
                continue;
            }
            // 추가로 담을 수 있는 경우
            if (dp_weight[i][j-1]+cur_w <= i) {
                dp[i][j] = cur_val+dp[i][j-1];
                dp_weight[i][j] = cur_w + dp_weight[i][j-1];
            } else { // 하나를 빼고 넣을 수 있는 경우
//                int mx1 = dp[i-cur_w][j]+dp[cur_w][j]; // 이번거를 담는 경우 >> 여기 주의!!
                int mx1 = dp[i-cur_w][j-1]+value[j]; // 이번거를 담는 경우 >> 여기 주의!!
                int mx2 = dp[i][j-1]; // 이번걸 포기하는 경우
                if (mx1 > mx2) {
                    dp[i][j] = mx1;
                    dp_weight[i][j] = dp_weight[i-cur_w][j-1] + weight[j];
                } else if (mx1 == mx2) {
                    if (dp_weight[i-cur_w][j]+dp_weight[cur_w][j] > dp_weight[i][j-1]) {
                        dp_weight[i][j] = dp_weight[i][j-1];
                    } else {
                        dp_weight[i][j] = dp_weight[i-cur_w][j]+dp_weight[cur_w][j];
                    }
                    dp[i][j] = mx1;
                } else {
                    dp[i][j] = mx2;
                    dp_weight[i][j] = dp_weight[i][j-1];
                }
            }
        }
    }
    cout << dp[K][N];
}
