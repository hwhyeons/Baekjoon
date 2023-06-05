
#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<int> per(n);
    iota(per.begin(), per.end(),0);
    int mx = -1;
    do {
        int gap = 0;
        for (int i = 0; i < n-1; ++i) {
            gap += abs(v[per[i]]-v[per[i+1]]);
        }
        mx = max(gap, mx);
    } while (next_permutation(per.begin(), per.end()));
    cout << mx;

}