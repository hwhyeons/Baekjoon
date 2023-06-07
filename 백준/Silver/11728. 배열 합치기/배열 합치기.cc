#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin >> a >> b;
    multiset<int> s;
    for (int i = 0; i < a+b; ++i) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    }
    for (auto k : s) {
        cout << k << " ";
    }
}