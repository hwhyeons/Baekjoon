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

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int answer = n;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        set<char> con; // contains set
        char before = '\0';
        for (int idx =0; idx<s.size();idx++) {
            if (con.find(s[idx]) == con.end()) {
                con.insert(s[idx]);
                before = s[idx];
            } else {
                if (before == s[idx]) {
                    continue;
                } else {
                    answer--;
                    break;
                }
            }
        }
    }
    cout << answer;
    
}
