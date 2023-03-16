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


int dfs(vector<string>& v, vector<bool>& visit, vector<string>& out, int r, int depth, int wantMin) {
    if (depth == r) {
        string stmp = "";
        for (auto k : out) {
            stmp.append(k);
        }
        int ans = stoi(stmp);
        if (ans > wantMin) {
            return ans;
        } else {
            return -1;
        }
    }
    int mn = INT_MAX;
    for (int i =0; i<v.size(); i++) {
        if (visit[i]) continue;
        out[depth] = v[i];
        visit[i] = true;
        auto tmp = dfs(v,visit,out,r,depth+1,wantMin);
        if (tmp != -1) {
            mn = min(mn,tmp);
        }
        visit[i] = false;
    }
    return mn;
}

void print_next(int len) {
    if (len == 9) {
        cout << "0\n";
        return;
    }
    for (int i =1; i<=len+1; i++) {
        cout << i;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    vector<string> v = {"1","2","3","4","5","6","7","8","9"};
    while (cin >> num){
        int mn = INT_MAX;
        int len = to_string(num).size(); // 숫자 자릿수
        vector<bool> visit(v.size());
        vector<string> out(len);
        int tmp = dfs(v,visit,out,len,0,num);
        if (tmp != 0 && tmp != INT_MAX) {
            mn = min(mn,tmp);
        }
        if (mn != INT_MAX && mn != 0) {
            cout << mn << "\n";
        } else {
            print_next(len);
        }
    }
}