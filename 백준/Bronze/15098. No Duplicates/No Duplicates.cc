#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    unordered_set<string> set;
    while (cin >> s) {
        if (set.contains(s)) {
            cout << "no";
            return 0;
        } else {
            set.insert(s);
        }
    }
    cout << "yes";
}