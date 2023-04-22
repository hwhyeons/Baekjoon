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
        while (true) {
            string s = to_string(num);
            if (!is_sorted(s.begin(),s.end())) {
                num--;
            } else {
                cout << "Case #"<< i << ": " << num << "\n";
                break;
            }
        }

    }
}