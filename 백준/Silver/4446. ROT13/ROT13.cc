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
#include <limits.h>

using namespace std;


vector<char> v1= {'a', 'i','y','e','o','u'};
vector<char> v2 ={'b','k','x','z','n','h','d','c','w','g','p','v','j','q','t','s','r','l','m','f'};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (getline(cin,s)) {
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isalpha(c)) {
                bool is_lower = islower(c);
                c = tolower(c);
                auto it1 = find(v1.begin(), v1.end(),c);
                bool is_ae = it1 != v1.end();
                vector<char>& vtmp = is_ae ? v1 : v2;
                int plus = is_ae ? 3 : 10;
                auto it = find(vtmp.begin(),vtmp.end(),c);
                char new_c = vtmp[((it-vtmp.begin())+plus)%(vtmp.size())];
                new_c = is_lower ? new_c : toupper(new_c);
                s[i] = new_c;
            }
        }
        cout << s << "\n";
    }

    return 0;
}
