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



bool get_acc(vector<int>& v, ll slice_n, ll want) {
    ll acc = 0LL;
    for (int i =0; i<v.size(); i++) {
        if (v[i] <= slice_n) continue;
        acc += (v[i]-slice_n);
        if (acc >= want) return true;
    }
    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt;
    ll want;
    cin >> cnt >> want;
    vector<int> v(cnt);
    for (int i=0; i<cnt; i++) {
        int t; cin >> t;
        v[i] = t;
    }
    sort(v.begin(),v.end());
    
    ll max_ans = -INT_MAX;
    ll mid;
    ll s = 0LL;
    ll e = v.back();
    while (s<=e) {
        mid = (s+e)/2;
        bool ok = get_acc(v,mid,want);
        if (ok) { // 갱신은 해놓고, 좀더 높여도 됨
            max_ans = max(max_ans,mid);
            s = mid+1;
        } else {
            e = mid-1;
        }
    }
    cout << max_ans;
}