#include <bits/stdc++.h>
#include <ranges>
typedef long long ll;
typedef long double ld;
using namespace std;

// vector<vector<int>> dp(101,vector<int>(500)); // 원소 값 : 사용할 전깃줄 개수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<int,int>> v(N);
    for (int i =0;i<N;i++) {
        int a,b; cin >> a >> b;
        v[i] = {a,b};
    }
    ranges::sort(v);

    // 차원 압축
    vector<int> dp(501);

    // r : 허용할 왼쪽 전깃줄
    // c : 사용할 금액
    for (int r=1;r<=N;r++) {
        for (int c=500;c>=1;c--) {
            int use_o = 0;
            if (v[r-1].second <= c) {
                use_o = 1 + dp[v[r-1].second-1];
            }
            int use_x = dp[c];
            dp[c] = max(use_o,use_x);
        }
    }
    cout << N - dp[500];
}
