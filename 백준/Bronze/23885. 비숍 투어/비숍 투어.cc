#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    ll t1,t2,t3,t4;
    cin >> t1 >> t2 >> t3 >> t4;
    ll gap1 = abs(t3-t1);
    ll gap2 = abs(t4-t2);
    if (gap1%2 == gap2%2) {
        cout << "YES";
    } else cout << "NO";

}