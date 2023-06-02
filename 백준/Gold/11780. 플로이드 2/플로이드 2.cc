#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

void getRoute(auto& ansV,auto& threw,int s, int e)
{
    if (threw[s][e] == s)
    {
        ansV.push_back(s);
        ansV.push_back(e);
        return;
    }
    getRoute(ansV,threw,s, threw[s][e]);
    ansV.pop_back();
    getRoute(ansV,threw,threw[s][e], e);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> v(n+1,vector<ll>(n+1,INT_MAX));
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,INT_MAX));
    vector<vector<int>> threw(n+1,vector<int>(n+1,INT_MAX)); // 거쳐간 노드


    for (int i = 0; i < m; ++i) {
        ll a,b,c;
        cin >> a >> b >> c;
        v[a][b] = min(c,v[a][b]);
        dp[a][b] = min(c,dp[a][b]);
    }
    for (int i = 1; i <= n; ++i) v[i][i] = 0; // 0 초기화
    for (int i = 1; i <= n; ++i) dp[i][i] = 0; // 0 초기화
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            threw[i][j] = i; // 처음에는 자기 자신이 거쳐간 경로
        }
    }

    for (int mid = 1; mid <= n; ++mid) {
        for (int start = 1; start <= n; ++start) {
            for (int end = 1; end <= n; ++end) {
                if (dp[start][mid] + dp[mid][end] < dp[start][end]) {
                    dp[start][end] = dp[start][mid] + dp[mid][end];
                    threw[start][end] = mid;
                }
            }
        }
    }

    // answer : only dist
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] == INT_MAX) {
                cout << 0 << " ";
            } else cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    
    // print path
    for (int start = 1; start <= n; ++start) {
        for (int end = 1; end <= n; ++end) {
            if (start == end) {
                cout << 0 << "\n";
                continue;
            }
            // 도달이 불가능한 경우
            if (dp[start][end] == INT_MAX) {
                cout << 0 << "\n";
                continue;
            }

            vector<int> ansV;
            getRoute(ansV,threw,start,end);
            cout << ansV.size() << " ";
            for (auto k : ansV) {
                cout << k << " ";
            }
            cout << "\n";

//            int cur = end; // 역추적 -> 도착지점부터
//            vector<int> allPath;
//            while (true) {
//                allPath.push_back(cur);
//                int beforeThrew = threw[start][cur];
//                if (beforeThrew == start) break;
//                else {
//                    cur = beforeThrew;
//                }
//            }
//            allPath.push_back(start);
//            cout << allPath.size() << " ";
//            copy(allPath.rbegin(),allPath.rend(),ostream_iterator<int>(cout," ")); // print reverse order
//            cout << "\n";
        }
    }
}