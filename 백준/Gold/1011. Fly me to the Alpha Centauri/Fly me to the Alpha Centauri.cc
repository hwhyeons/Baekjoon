#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
typedef long long ll;
using namespace std;

// -----------------------------------------
// -----------------------------------------
// -----------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    ll tcnt;
    cin >> tcnt;
    map<ll,ll> m;
    ll cur = 1;
    ll curAns = 1;
    ll dx = 2;
    while (1) {
        m.insert({ cur,curAns });
        cur += dx;
        curAns++;
        m.insert({ cur,curAns });
        curAns++;
        cur += dx;
        dx++;
        if (cur >= 2147483647LL +1000LL) break;
    }

    for (size_t i = 0; i < tcnt; i++) {
        ll a, b;
        cin >> a >> b;
        ll gap = b - a;
        if (gap == 0) throw "err";
        if (gap == 1) {
            cout << 1 << "\n";
        } else if (gap == 2) {
            cout << 2 << "\n";
        } else if (gap == 3) {
            cout << 3 << "\n";
        } else {
            auto it = m.upper_bound(gap-2);
            if (it != m.begin()) {
                it--;
            }
            auto [key, val] = *it;
            cout << val+2 << "\n";
        }
    }

}