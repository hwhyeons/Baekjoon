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
    long long a,b;
    cin >> a >> b;
    if (a == b) {
        cout << a;
        return 0;
    } else if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (a >= 0){
        cout << b*(b+1)/2 - (a-1)*(a)/2;
    } else {
        cout << b*(b+1)/2 - (-a+1)*(-a)/2;
    }
}
