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
        string s;
        string origin;
        cin >> s;
        string tmp(s);
        std::sort(tmp.begin(), tmp.end(),greater<char>());
        if (tmp == s) { // 원래 맨 마지막인 경우
            cout << s << "\n";
        } else {
            next_permutation(s.begin(), s.end());
            cout << s << "\n";
        }
    }
}