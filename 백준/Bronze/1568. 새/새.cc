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
    int cur = 1;
    int left = n;
    int acc = 0;
    for(;;) {
        if (cur > left) {
            cur = 1;
            continue;
        } else {
            left -= cur;
            acc ++;
            cur++;
            if (left == 0) {
                break;
            }
        }
    }
    cout << acc;
}
