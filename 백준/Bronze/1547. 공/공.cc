#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int i = 0;
    int cur = 1;
    while (i++ < n) {
        int x,y;
        cin >> x >> y;
        if (x == cur) {
            cur = y;
        } else if (y == cur) {
            cur = x;
        }
    }
    cout << cur;
}
