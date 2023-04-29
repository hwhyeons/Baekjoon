#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    deque<int> a;
    deque<int> b;
    int ans = 0;
    int idx =0;
    for (char ch : s) {
        if (ch == 'A') {
            a.push_back(idx);
        } else if (ch == 'B') {
            b.push_back(idx);
        } else {
            if (!b.empty()) {
                b.pop_front();
                ans++;
            }
        }
        idx++;
    }
    while (!a.empty() && !b.empty()) {
        if (b.back() > a.back()) {
            a.pop_back();
            b.pop_back();
            ans++;
        } else {
            a.pop_back();
        }
    }
    cout << ans;
}