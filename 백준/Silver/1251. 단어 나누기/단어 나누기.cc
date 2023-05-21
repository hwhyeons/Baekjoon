#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string s1,s2,s3;
    set<string> all;
    for (int i = 1; i < s.size(); ++i) {
        for (int j = i+1; j < s.size(); ++j) {
            s1 = s.substr(0,i);
            s2 = s.substr(i,j-i);
            s3 = s.substr(j);
            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());
            reverse(s3.begin(), s3.end());
            string s4 = s1+s2+s3;
            all.insert(s4);
        }
    }
    cout << *all.begin();
}