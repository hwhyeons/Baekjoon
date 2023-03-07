#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string all;
    string bomb;
    cin >> all;
    cin >>  bomb;
    string s = "";
    for (int i=0;i<all.size();i++) {
        s.append(all.substr(i,1));
        while (true) {
            if (s.size() < bomb.size()) {
                break;
            }
            string sub = s.substr(s.size()-bomb.size(),bomb.size());
            if (sub == bomb) {
                s.erase(s.size()-bomb.size(),bomb.size());
            } else {
                break;
            }
        }
    }
    if (s == "") {
        cout << "FRULA";
    } else {
        cout << s;
    }
}