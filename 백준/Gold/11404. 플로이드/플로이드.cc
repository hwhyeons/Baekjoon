#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <map>

#define ll long long

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> v(n+1,vector<ll>(n+1,INT_MAX));
    for (int i = 1; i < v.size(); ++i) {
        v[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        ll t1,t2,t3; cin>>t1>>t2>>t3;
        v[t1][t2] = min(v[t1][t2],t3);
    }

    // 플로이드 워셜
    for (int i = 1; i < v.size(); ++i) { // 거쳐가는 노드
        for (int j = 1; j < v.size(); ++j) { // 시작 노드
            for (int k = 1; k < v.size(); ++k) { // 도착 노드
                if (j==k) continue;

                ll mn1 = v[j][k];
                ll mn2 = v[j][i]+v[i][k];
                v[j][k] = min(mn1, mn2);
            }
        }
    }
    for (int i = 1; i < v.size(); ++i) {
        for (int j = 1; j < v.size(); ++j) {
            if (v[i][j] == INT_MAX) {
                cout << 0 << " ";
            } else {
                cout << v[i][j] << " ";
            }
        }
        cout << "\n";
    }


}
