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


unordered_set<int> s;


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<string> v;
    for(int i=1; i <= n; i++) {
        int count = 2*n-2*i;
        string s = "";
        for(int j=1;j<=i;j++) {
            s.append("*");
        }
        for(int j=1;j<=count;j++) {
            s.append(" ");
        }
        for(int j=1;j<=i;j++) {
            s.append("*");
        }
        cout << s << "\n";
        v.push_back(s);
    }
    for (auto it = v.rbegin()+1; it != v.rend(); it++) {
        cout << *it << "\n";
    }

    
}
