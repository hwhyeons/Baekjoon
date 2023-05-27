#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        auto it = s.find("+");
        if (it == string::npos) {
            cout << "skipped\n";
        } else {
            cout << stoi(s.substr(0,it)) + stoi(s.substr(it+1)) << "\n";
        }
    }
}