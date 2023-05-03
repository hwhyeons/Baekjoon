#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l,r;
    cin >> l >> r;
    ll acc = 0.0;
    ll cur = l;
    int cst = 2;
    while (true) {
        cur = cur*(r/100.0);
        if (cur <= 5) break;
        acc += cst*cur;
        cst*=2;
    }
    cout << (long long)acc;

}