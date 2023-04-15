#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    if (s.find("11") != string::npos || s.find("22") != string::npos) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}