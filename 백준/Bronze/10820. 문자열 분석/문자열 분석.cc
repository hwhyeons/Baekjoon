#include <iostream>
#include <algorithm>
#include <string>
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
    while (getline(cin,s)) {
        if (s == "fin") {
            break;
        }
        int up = count_if(s.begin(),s.end(),[](char c){return isupper(c);});
        int space = count_if(s.begin(),s.end(),[](char c){return c==' ';});
        int number = count_if(s.begin(),s.end(),[](char c){return isdigit(c);});
        int low = s.size()-up-space-number;
        cout << low << " " << up << " " << number << " " << space << "\n";
    }
}
