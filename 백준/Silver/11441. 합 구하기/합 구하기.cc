#include <bits/stdc++.h>
#include <ranges>

#define ll long long
#define inf INT_MAX
#define rv ranges::views

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    vector<int> v(n);
    cin >> v[0];
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int t1,t2;
        cin >> t1 >> t2;
        if (t1 > t2) swap(t1,t2);
        else if (t1 == t2) {
            if (t1 == 1) {
                cout << v[0] << "\n";
            } else cout << v[t1-1]-v[t1-2] << "\n";
        } else {
            if (t1 == 1) {
                cout << v[t2-1] << "\n";
            } else cout << v[t2-1] - v[t1-2] << "\n";
        }
    }
}
