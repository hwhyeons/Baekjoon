#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <numeric>
#include <vector>
#include <set>
#include<bitset>
#include <map>
#include <stack>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    int i = 0;
    cin >> n;
    bitset<21> base("000000000000000000000");
    while (i++ < n) {
        string str;
        cin >> str;
        if (str == "check") {
            cin >> tmp;
            cout << base[tmp] << "\n";
        }
        else if (str == "add") {
            cin >> tmp;
            base[tmp] = base[tmp] | 1;
        }
        else if (str == "remove") {
            cin >> tmp;
            base[tmp] = 0;
        }
        else if (str == "toggle") {
            cin >> tmp;
            base[tmp].flip();
        }
        else if (str == "all") {
            base.reset();
            base.flip();
            //s = base;
            // s = set<int>(v.begin(), v.end());
        }
        else if (str == "empty") {
            base.reset();
            // s.clear(); 
        }
    }
}
