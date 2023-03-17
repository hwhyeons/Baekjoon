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


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int get_acc(vector<vector<int>>& v, vector<vector<bool>>& visit,int y, int x) {
    int acc = 1;
    visit[y][x] = true;
    for (int i =0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || ny < 0 || nx >= v[0].size() || ny >= v.size()) continue;
        if (visit[ny][nx]) continue;
        if (v[ny][nx] != 0) continue;
        acc += get_acc(v,visit,ny,nx);
    }
    return acc;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n,k;
    cin >> m >> n >> k;
    vector<vector<int>> v(m,vector<int>(n));
    vector<vector<bool>> visit(m,vector<bool>(n));
    for (int i =0; i<k; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j<y2; j++) {
            for (int t = x1; t<x2; t++) {
                v[j][t]=1;
            }
        }
    }


    vector<int> ans;
    for (int i =0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (visit[i][j]) continue;
            if (v[i][j] != 0) continue;
            int acc = get_acc(v,visit,i,j);
            ans.push_back(acc);
        }
    }

    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for (auto tmp : ans) {
        cout << tmp << " ";
    }


}