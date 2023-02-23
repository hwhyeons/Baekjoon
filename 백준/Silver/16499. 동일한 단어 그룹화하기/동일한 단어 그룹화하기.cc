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
    unordered_set<string> s;
    while (i++ < n) {
        string t;
        cin >> t;
        sort(t.begin(),t.end());
        s.insert(t);
    }
    cout << s.size();
}
