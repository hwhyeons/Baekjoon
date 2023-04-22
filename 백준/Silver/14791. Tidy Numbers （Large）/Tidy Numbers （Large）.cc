#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcnt;
    cin >> tcnt;
    for (int i = 1; i <= tcnt; ++i) {
        ll num;
        cin >> num;
        string s = to_string(num);
        while (true) {
            auto it = is_sorted_until(s.begin(), s.end());
            if (it == s.end()) {
                cout << "Case #"<< i << ": " << s << "\n";
                break;
            } else {
                it--;
                *it = *it - 1;
                it++;
                while (it != s.end()) {
                    *it = '9';
                    it++;
                }
                num = stoll(s);
                s = to_string(num);
            }
        }
    }
}