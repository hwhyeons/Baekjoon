#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ll n;
    cin >> n;
//    1 : 상근;
//    2 : 창영;
//    3 : 상근;
//    4 : 상근
//    5 : 창영;
//    -----;
//    6 : 상근;
//    7 : 창영;
//    8 : 상근
//    9 : 상근;
//    10 : 창영;

    if (n%5 == 0 || n%5 == 2) {
        cout << "CY";
    } else cout << "SK";
}