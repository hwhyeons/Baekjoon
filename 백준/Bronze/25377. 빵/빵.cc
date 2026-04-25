#include <algorithm>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <limits.h>
#include <iostream>
#include <string>

using namespace std;
#define ll long long


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int t1,t2;
    int ans = INT_MAX;
    while (n--) {
        cin >> t1 >> t2;
        if (t1 > t2) continue;
        ans = min(ans,t2);
    }
    cout << (ans == INT_MAX ? -1 : ans);

}
