#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n ;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; ++i) {
        int a,b; cin >> a >> b;
        v.emplace_back(a,b);
    }
    int ans = 0;
    for (int i=n; i>=0; i--) {
        ans = 0;
        for (int j=0; j<n; j++) {
            auto [a,b] = v.at(j);
            if (a <= i && i <= b) ans++;
        }
        if (ans == i) goto ansLb;
    }
    ans = 0;
    ansLb:
    cout << (ans == 0 ? -1 : ans);
}