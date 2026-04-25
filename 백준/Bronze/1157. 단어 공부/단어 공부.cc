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
    string s;
    cin >> s;
    int count_ = 'Z'-'A'+1;
    vector<int> v(count_);
    for (int i =0; i< s.size(); i++) {
        char c = s[i];
        c = toupper(c);
        v[c - 'A'] += 1;
    }
    auto it = max_element(v.begin(),v.end());
    int max_count = count(v.begin(),v.end(),*it);
    if (max_count > 1) {
        cout << "?";
    } else {
        int k = it-v.begin()+'A';
        cout << (char)k;
    }
}