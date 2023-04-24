#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s1,s2;
    cin >> n >> s1 >> s2;
    if (s1.size() != s2.size()) {
        cout << "Deletion failed";
        return 0;
    }
    if (n%2 == 0) {
        if (s1 == s2) {
            cout << "Deletion succeeded";
        } else cout << "Deletion failed";
    } else {
        replace(s2.begin(), s2.end(),'1','2');
        replace(s2.begin(), s2.end(),'0','1');
        replace(s2.begin(), s2.end(),'2','0');
        if (s1 == s2) {
            cout << "Deletion succeeded";
        } else cout << "Deletion failed";
    }
}