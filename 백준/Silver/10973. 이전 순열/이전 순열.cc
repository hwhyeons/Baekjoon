
#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (prev_permutation(v.begin(),v.end())) {
        for (auto k : v) {
            cout << k <<" ";
        }
    } else {
        cout << -1;
    }
}