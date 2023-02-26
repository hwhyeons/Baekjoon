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
#include <valarray>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    valarray<int> va(5);
    cin >> va[0] >> va[1] >> va[2] >> va[3] >> va[4];
    cout << va.sum()/va.size() << endl; 
    sort(begin(va),end(va));
    cout << va[2];
}
