
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
    iota(v.begin(), v.end(), 1);
    do {
        for (auto k : v) {
            cout << k << " ";
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
}