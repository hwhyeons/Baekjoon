#include <bits/stdc++.h>
#include <iostream>


typedef long long ll;
using namespace std;


int main() {
    int tcnt;
    cin >> tcnt;
    cin.tie(nullptr);

    vector<ll> v(1000001,1); 
    for (int i = 2; i <= 1000000; i++) {
        v[i] += i;
        for (int j = 2; j*i <= 1000000; j++) {
            v[j*i] += i;
        }
    }

    vector<ll> ans(1000001); 
    for (int i =1; i<=1000000; i++) {
        ans[i] = ans[i-1] + v[i];
    }

    while (tcnt--) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}