#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int cnt = 0;
    while (true) {
        if (s.size() == 1) {
            string ans = stoi(s)%3 == 0 ? "YES" : "NO";
            cout << cnt << "\n";
            cout << ans;
            break;
        }
        int acc = 0;
        for (char c: s) {
            acc += c-'0';
        }
        s = to_string(acc);
        cnt++;
    }
}