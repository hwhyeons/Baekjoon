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
#include <queue>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v1;
    vector<ll> v2;
    for (int i =0; i<n; i++) {
        ll t;
        cin >> t;
        v1.push_back(t);
    }
    for (int i =0; i<n; i++) {
        ll t;
        cin >> t;
        v2.push_back(t);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),[](ll a,ll b){
        if (a > b) return true;
        else return false;
    });
    ll ans = 0;
    for (int i =0; i<n;i++) {
        ans += v1[i] * v2[i];
    }
    cout << ans;
}