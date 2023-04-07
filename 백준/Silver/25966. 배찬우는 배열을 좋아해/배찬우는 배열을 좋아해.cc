#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t;
            cin >> t;
            v[i][j] = t;
        }
    }
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int t1,t2,t3;
            cin >> t1 >> t2 >> t3;
            v[t1][t2] = t3;
        } else if (t == 1) {
            int t1,t2;
            cin >> t1 >> t2;
            swap(v[t1],v[t2]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}