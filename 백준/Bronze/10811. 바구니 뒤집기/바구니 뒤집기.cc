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
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    while(m--){
        int a,b;
        cin >> a >> b;
        reverse(v.begin()+a-1,v.begin()+b);
    }
    for (auto t : v) cout << t << " ";
}