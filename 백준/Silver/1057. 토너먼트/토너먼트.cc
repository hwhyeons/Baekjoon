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
    int n,a,b;
    cin >> n >> a >> b;
    int ans = 1;
    int teamA,teamB;
    while (true) {
        teamA = (a+1)/2;
        teamB = (b+1)/2;
        if (teamA == teamB) break;
        ans++;
        if (n == 1) {
            ans = -1;
            break;
        }
        a = teamA;
        b = teamB;
        if (n%2 == 0) {
            n/=2;
        } else {
            n = n/2 + 1;
        }
    }
    cout << ans;
}