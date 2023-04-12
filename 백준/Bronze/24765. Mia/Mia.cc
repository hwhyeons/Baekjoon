#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (true) {
        getline(cin, s);
        if (s == "\n") continue;
        int a1,a2,b1,b2;
        a1 = s[0]-'0';
        a2 = s[2]-'0';
        b1 = s[4]-'0';
        b2 = s[6]-'0';
        if (a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0) break;
        int k1 = max(10*a1+a2,10*a2+a1);
        int k2 = max(10*b1+b2,10*b2+b1);
        int p1 = 0,p2=0;
        if (k1 == 21) {
            p1 = 500000;
        }
        if (k2 == 21) {
            p2 = 500000;
        }
        if (k1%11 == 0) {
            p1 = max(p1,k1*1000);
        }
        if (k2%11 == 0) {
            p2 = max(p2,k2*1000);
        }
        p1 = max(p1,k1);
        p2 = max(p2,k2);
        if (p1 > p2) {
            cout << "Player 1 wins.";
        } else if (p2 > p1){
            cout << "Player 2 wins.";
        } else {
            cout << "Tie.";
        }
        cout << "\n";
    }
}
