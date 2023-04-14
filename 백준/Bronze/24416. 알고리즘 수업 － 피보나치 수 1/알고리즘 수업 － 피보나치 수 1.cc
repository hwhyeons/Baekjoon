#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;


ll ans1 = 0;
ll fib(ll n) {
    ans1++;
    if (n == 1 || n == 2) return 1;
    else return (fib(n - 1) + fib(n - 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << fib(n) << " ";
    if (n <= 2) {
        cout << 1;
    } else {
        cout << n-2;
    }
}