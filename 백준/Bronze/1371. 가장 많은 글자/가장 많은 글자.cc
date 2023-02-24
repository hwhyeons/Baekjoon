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
    string s;
    const int all = 'z'-'a'+1;
    vector<int> v(all);
    fill(v.begin(),v.end(),0);
    while (cin >> s) {
        for (int i =0; i<s.size();i++) {
            v[s[i]-'a'] +=1;
        }
    }
    auto it = max_element(v.begin(),v.end());
    int mx = *it;
    string answer = "";
    for (int i =0; i<v.size(); i++) {
        if (v[i] == mx) {
            answer += ((char)(i+(int)('a')));
        }
    }
    sort(answer.begin(),answer.end());
    cout << answer;
}
