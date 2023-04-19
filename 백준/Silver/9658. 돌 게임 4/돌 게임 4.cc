#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;
//    1 : 창영;
//    2 : 상근;
//    3 : 창영;
//    4 : 상근;
//    5 : 상근;
//    6 : 상근;
//    7 : 상근;
    if (n%7 == 1 || n%7 == 3) {
        cout << "CY";
    } else cout << "SK";
}