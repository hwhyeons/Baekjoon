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
    string s;
    for(;;) {
        int cnt = 0;
        getline(cin,s);
        if (s == "#") break;
        cnt += count_if(s.begin(),s.end(),[](char c) {
            if (c == 'a' || c=='e' || c=='i' || c=='u' || c=='o'
            || c == 'A' || c=='E' || c=='I' || c=='U' || c=='O'){
                return true;
            } else return false;
        });
        cout << cnt << "\n";

    }
}
