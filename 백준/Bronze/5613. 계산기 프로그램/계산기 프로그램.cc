#include <bits/stdc++.h>
#include <ranges>

typedef long long ll ;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string c;
    cin >> c;
    int ans = stoi(c);
    while (true) {
        string c;
        cin >> c;
        if (c == "=") break;
        if (c == "+") {
            cin >> c;
            ans += stoi(c);
        } else if (c == "-") {
            cin >> c;
            ans -= stoi(c);
        } else if (c == "*") {
            cin >> c;
            ans *= stoi(c);
        } else if (c == "/") {
            cin >> c;
            ans /= stoi(c);
        }
    }
    cout << ans;

}
