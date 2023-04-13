#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin >> a>> b;
    int ans1 = a;
    int ans2 = b;
    int len = 2;
    while (true) {
        len++;
        int c = (a+b)%10;
        if (b == ans1 && c == ans2) {
            break;
        }
        a = b;
        b = c;
    }
    cout << len;
}