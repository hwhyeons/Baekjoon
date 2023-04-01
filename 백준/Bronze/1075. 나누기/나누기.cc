#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    string tmp;
    getline(cin,tmp);
    int f = stoi(tmp);
    int last1 = s.size()-1;
    int last2 = last1-1;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            s[last2] = i+'0';
            s[last1] = j+'0';
            int num = stoi(s);
            if (num%f == 0) {
                int ans = stoi(s.substr(s.size()-2));
                if (ans < 10) {
                    cout << 0 << ans;
                } else {
                    cout << ans;
                }
                return 0;
            }
        }
    }

}

