
#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <deque>
#include <limits>
#include <set>
#include <map>

typedef long long ll;
typedef long double ld;
using namespace std;

int T,W;

// 시간, 움직인횟수, 현재시점 (0 or 1)
vector<vector<vector<ll>>> dp(1001,vector<vector<ll>>(31,vector<ll>(3,-1ll)));


ll dfs(vector<int>& v,int time, int move, int oneTwo) {
    if (move==-1) return 0; // 움직임이 안되는 경우
    if (time==0) return 0;
    // 이미 저장
    if (dp[time][move][oneTwo] != -1) {
        return dp[time][move][oneTwo];
    }

    int revOneTwo = oneTwo==1 ? 2 : 1;
    // 그대로 있는 경우 + 현재 그대로
    ll ans1 = dfs(v,time-1,move,oneTwo);

    // 이전상태에서 움직여서 여기로 왔다고 가정
    ll ans2 = dfs(v,time-1,move-1,revOneTwo);
    ll localAns = max(ans1,ans2);
    if (v[time] == oneTwo) localAns++;
    dp[time][move][oneTwo] = localAns;
    return dp[time][move][oneTwo];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> W;
    vector<int> v(T+1);
    for (int t=1;t<=T;t++) {
        cin >> v[t];
    }

    // 시간이 1초일 때
    if (v[1] == 1) {
        dp[1][0][1] = 1; // 1초에 0번 움직이고 현재1
        dp[1][0][2] = 0;
    } else {
        dp[1][0][2] = 0;
        dp[1][0][1] = 0;
    }
    ll MAX=0;
    for (int w=0;w<=W;w++) {
        MAX = max(dfs(v,T,w,1),dfs(v,T,w,2));
    }
    cout << MAX;
}