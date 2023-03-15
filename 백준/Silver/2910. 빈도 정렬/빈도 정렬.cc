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
#include <limits.h>
#include <queue>
#define ll long long

using namespace std;



class tp {
public:
    int cnt = 0;
    int start = -1;
    int val = -1;
};

bool compare(tp* a, tp* b){
    if (a->cnt > b->cnt) {
        return true;
    } else if (a->cnt == b->cnt) {
        if (a->start < b->start) {
            return true;
        } else {
            return false;
        }
    } else return false;
}

// pair : 등장 횟수 / 시작점
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,c;
    cin >> n >> c;
    unordered_map<int,tp*> v;
    for (int i =0; i<n; i++) {
        int t;
        cin >> t;
        if (v.count(t) == 0) {
            tp* tmp = new tp;
            tmp->start = i;
            tmp->val = t;
            tmp->cnt = 1;
            v[t] = tmp;
        } else {
            tp* tmp = v[t];
            tmp->cnt = tmp->cnt + 1;
        }
        // v[t] = tp;
    }
    vector<tp*> v1;
    for (auto it = v.begin(); it != v.end(); it++) {
        v1.push_back((*it).second);
    }
    sort(v1.begin(),v1.end(),compare);
    for (int i = 0; i<v1.size(); i++) {
        auto p = *(v1[i]);
        if (p.start != -1) {
            for (int j =0; j<p.cnt; j++) {
                cout << p.val << " ";
            }
        }
    }
}