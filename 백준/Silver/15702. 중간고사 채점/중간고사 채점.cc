#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int minP = -1;
    int maxAcc = -1;
    for (int i = 0; i < m; ++i) {
        int name;
        cin >> name;
        int acc = 0;
        for (int j = 0; j < n; ++j) {
            char tmp;
            cin >> tmp;
            if (tmp == 'O') {
                acc += v.at(j);
            }
        }
        if (acc >= maxAcc) {
            if (acc == maxAcc) {
                minP = min(name, minP);
            } else {
                minP = name;
            }
            maxAcc = acc;
        }
    }
    cout << minP << " " << maxAcc;
}