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
    int n;
    cin >> n;
    vector<pair<int,int>> v; // index + value (A 배열)
    for (int i =0;i<n;i++) {
        int t;
        cin >> t;
        v.push_back(make_pair(i,t));
    }
    sort(v.begin(),v.end(),[](auto p1, auto p2){
        if (p1.second < p2.second) {
            return true;
        } else if (p1.second == p2.second) {
            if (p1.first < p2.first) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    });
    vector<int> p(v.size());
    for (int i =0;i<v.size(); i++) {
        p[v[i].first] = i;
    }
    for (auto k : p) {
        cout << k << " ";
    }
}