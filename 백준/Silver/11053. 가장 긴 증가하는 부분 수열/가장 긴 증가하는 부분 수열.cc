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
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) {
        int t; cin >> t;
        v[i] = t;
    }
    vector<int> ans(n);
    vector<int> mn(n);
    ans[n-1] = 1;
    mn[n-1] = v[n-1];
    for (int i =n-2; i>=0; i--) {
        int cur_val = v[i];
        int max_tmp = 1;
        mn[i] = cur_val;
        ans[i] = 1;
        for (int j = i+1; j<n; j++) {
            if (mn[j] > cur_val) {
                max_tmp = max(max_tmp,1+ans[j]);
            }
        }
        ans[i] = max_tmp;
    }

    cout << *max_element(ans.begin(),ans.end());
}