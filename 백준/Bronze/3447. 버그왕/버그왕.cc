#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (getline(cin,s)){
        while (regex_search(s, regex("BUG"))) {
            s = regex_replace(s,regex("BUG"),"");
        }
        cout << s << "\n";
    }
}