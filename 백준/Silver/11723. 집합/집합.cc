#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
    set<int> s;
    set<int> empty_set;
    set<int> base = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    vector<int> v(20);
    iota(v.begin(), v.end(), 20);
    while (i++ < n) {
        string str;
        cin >> str;
        if (str == "check") {
            cin >> tmp;
            cout << (s.find(tmp) != s.end()) << "\n";
        }
        else if (str == "add") {
            cin >> tmp;
            if (s.find(tmp) == s.end()) {
                s.insert(tmp);
            }
        }
        else if (str == "remove") {
            cin >> tmp;
            if (s.find(tmp) != s.end()) {
                s.erase(tmp);
            }
        }
        else if (str == "toggle") {
            cin >> tmp;
            if (s.find(tmp) != s.end()) {
                s.erase(tmp);
            }
            else {
                s.insert(tmp);
            }
        }
        else if (str == "all") {
            s = base;
            // s = set<int>(v.begin(), v.end());
        }
        else if (str == "empty") {
            s = empty_set;
            // s.clear(); 
        }
    }
}
