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

class cd {
public:
    int x,y;
};

ll get_chicken_dist(vector<vector<int>>& v, vector<cd>& out) {
    ll acc = 0LL;
    // 차집합
    for (int i =0; i<v.size(); i++) {
        for (int j =0; j<v.size(); j++) {
            if (v[i][j] == 1) {
                ll mn = LLONG_MAX;
                for (auto c : out) {
                    ll dst = abs(c.x-j) + abs(c.y-i);
                    mn = min(dst,mn);
                }
                acc += mn;
            }
        }
    }
    return acc;
}

ll dfs(vector<vector<int>>& v, vector<cd>& out, int n, int r, int depth, int idx, vector<cd>& chs) {
    if (depth == r) {
        // for (auto coor : out) {
        //     v[coor.y][coor.x] = 0; // 빈집으로 변경
        // }
        ll dist = get_chicken_dist(v,out);
        // for (auto coor : out) {
            // v[coor.y][coor.x] = 2; // 다시 치킨집으로 
        // }
        return dist;
    }
    ll mn = LLONG_MAX;
    for(int i = idx; i<chs.size(); i++) {
        out[depth] = chs[i];
        ll tmp = dfs(v,out,n,r,depth+1,i+1,chs);
        mn = min(mn,tmp);
    }
    return mn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(n));
    for (int i =0; i<n;i++) {
        for (int j=0;j<n;j++) {
            int t; cin >> t;
            v[i][j] = t;
        }
    }

    vector<cd> chicken;
    // 치킨집 정보
    for (int i =0; i<n;i++) {
        for (int j=0;j<n;j++) {
            if (v[i][j] == 2) {
                cd t;
                t.x = j;
                t.y = i;
                chicken.push_back(t);
            }
        }
    }

    // 순열 이용해서 전부 다 계산
    int all_chicken = chicken.size();
    ll ans = LLONG_MAX;
    for (int take_count = 1; take_count <= m; take_count++) {
        vector<cd> out(take_count); // 가져갈 대상 찾기
        ll ll_tmp = dfs(v,out,all_chicken,take_count,0,0,chicken);
        ans = min(ans,ll_tmp);
    }
    cout << ans;

}