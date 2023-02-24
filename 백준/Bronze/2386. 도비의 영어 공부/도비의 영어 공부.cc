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
    for(;;) {
        string s;
        getline(cin,s);
        if (s[0] == '#') break;
        char check = s[0];
        char check1 = tolower(check);
        char check2 = toupper(check);
        int ans = count(s.begin()+2,s.end(),check1) + count(s.begin()+2,s.end(),check2);
        cout << check << " " << ans << "\n";
    }
}
