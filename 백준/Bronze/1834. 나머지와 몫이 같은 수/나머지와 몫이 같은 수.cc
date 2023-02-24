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
    long long q = 1LL; // 몫이자 나머지
    long long acc = 0LL;
    for(long long q = 1;q <n; q++) {
        long long k = q*(n+1);
        acc += k;
    }
    cout << acc;
}
