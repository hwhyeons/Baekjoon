#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcnt;
    cin >> tcnt;
    while (tcnt--) {
        int p,m;
        cin >> p >> m;
        unordered_set<int> s;
        for (int i = 0; i < p; ++i) {
            int t;
            cin >> t;
            s.insert(t);
        }
        cout << p-s.size() << "\n";
    }
}