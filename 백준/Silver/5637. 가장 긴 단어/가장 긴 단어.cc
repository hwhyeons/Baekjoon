#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string mx = "";
    while (true) {
        string s;
        cin >> s;
        if (s == "E-N-D") break;
        string s1;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isalnum(c) || c == '-') {
                s1.append(s.substr(i,1));
            }
        }
        if (s1.size() > mx.size()) {
            mx = s1;
        }
    }
    for_each(mx.begin(),mx.end(),[](char c){
        cout << string(1,(char)(tolower(c)));
    });

}