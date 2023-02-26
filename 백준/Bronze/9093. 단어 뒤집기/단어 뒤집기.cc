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

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    for (int i =0; i<n; i++) {
        string s;
        getline(cin,s);
        stringstream ss;
        ss.str(s);
        string tmp;
        while (getline(ss,tmp,' ')) {
            reverse(tmp.begin(),tmp.end());
            cout << tmp << " ";
        }
        cout << "\n";
    }
}
