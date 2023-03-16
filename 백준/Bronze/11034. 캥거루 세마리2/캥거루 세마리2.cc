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
    int a,b,c;
    while (cin >> a >> b >> c) {
        int cnt = 0;
        while (true) {
            int gap1 = b-a;
            int gap2 = c-b;
            int mx = max(gap1,gap2);
            if (mx >= 2) {
                if (mx == gap1) {
                    int na = a;
                    int nb = a+1;
                    int nc = b;
                    a = na;
                    b = nb;
                    c = nc;
                } else {
                    int na = b;
                    int nb = b+1;
                    int nc = c;
                    a = na;
                    b = nb;
                    c = nc;
                }
            } else {
                break;
            }
            cnt++;
        }
        cout << cnt << "\n";
    }
}