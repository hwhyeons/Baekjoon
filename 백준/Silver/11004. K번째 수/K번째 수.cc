#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    std::sort(v.begin(), v.end());
    cout << v[k-1];

}