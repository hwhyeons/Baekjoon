#include <ranges>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>

using namespace std;

vector<vector<int>> v;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
void dfs(vector<vector<bool>>& visit,int y, int x, int water_height) {
    visit[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || ny < 0 || nx >= v.size() || ny >= v.size()) continue;
        if (visit[ny][nx]) continue;
        if (v[ny][nx] <= water_height) continue;
        dfs(visit,ny,nx,water_height);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    v = vector<vector<int>>(n,vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t; cin >> t;
            v[i][j] = t;
        }
    }
    int ans = 0;
    for (int h = 0; h <= 100; h++) {
        vector<vector<bool>> visit(n,vector<bool>(n));
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visit[i][j]) continue;
                if (v[i][j] <= h) continue;
                dfs(visit,i,j,h);
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}