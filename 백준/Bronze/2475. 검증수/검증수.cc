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
    int n = 0;
    int t;
    for (int i=0;i<5;i++) {
        cin >> t;
        n = n+ t*t;
    }
    cout << n%10;
    
}
