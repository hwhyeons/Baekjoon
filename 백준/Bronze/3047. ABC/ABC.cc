#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    std::sort(v.begin(), v.end());
    for (int i = 0; i < 3; ++i) {
        char t;
        cin >> t;
        if (t == 'A') {
            cout << v[0] << " ";
        } else if (t == 'B') {
            cout << v[1] << " ";
        } else {
            cout << v[2] << " ";
        }
    }

}