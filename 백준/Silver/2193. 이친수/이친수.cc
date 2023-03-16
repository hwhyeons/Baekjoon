#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <limits.h>
#include <queue>
#define ll long long

using namespace std;


vector<ll> v(91);

ll f(ll n) {
    if (n == 3) return 2;
    if (n==4) return 3;
    if (v[n] != 0) return v[n];
    else {
        ll tmp = f(n-1)+f(n-2);
        v[n] = tmp;
        return tmp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    if (n <= 2) {
        cout << 1;
    } else {
        v[3] = 2;
        v[4] = 3;
        cout << f(n);
    }
}