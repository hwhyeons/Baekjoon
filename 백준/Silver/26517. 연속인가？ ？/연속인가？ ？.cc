#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    cout << (a*n+b==c*n+d ? "Yes "+to_string(a*n+b) : "No");
}