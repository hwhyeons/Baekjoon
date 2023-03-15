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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int m;
    cin >> n >> m;
    vector<int> v;
    for (int i =0; i<n;i++) {
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    int s =0,e=v.size()-1;
    int cnt = 0;
    while (s<e) {
        int acc = v[s]+v[e];
        if (acc == m) {
            cnt++;
            s++;
            e--;
        } else if (acc < m) {
            s++;
        } else {
            e--;
        }
    }
    cout << cnt;
}