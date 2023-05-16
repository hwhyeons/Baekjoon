#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int charCount = 'z'-'a'+1;
    ll ans = 1;
    if (s[0] == 'c') {
        ans = charCount;
    } else {
        ans = 10;
    }
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == 'c') {
            if (s[i-1] == 'c') {
                ans = (ans*(charCount-1))%1000000009;
            } else ans = (ans*(charCount))%1000000009;
        } else {
            if (s[i-1] == 'd') ans = (ans*9)%1000000009;
            else ans = (ans*10)%1000000009;
        }
        ans = (ans%1000000009);
    }
    cout << ans;

}