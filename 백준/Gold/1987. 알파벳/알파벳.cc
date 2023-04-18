#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;
vector<vector<char>> v;
vector<vector<bool>> visit_idx;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int C,R;

int ans = 1;
void dfs(int y, int x, vector<bool>& visit_alp, int cnt) {
    ans = max(ans,cnt);
    for (int i = 0; i < 4; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
        if (visit_alp.at(v[ny][nx]-'A')) continue;
        if (visit_idx[ny][nx]) continue;
        visit_alp.at(v[ny][nx]-'A') = true;
        visit_idx[ny][nx] = true;
        dfs(ny,nx,visit_alp,cnt+1);
        visit_alp.at(v[ny][nx]-'A') = false;
        visit_idx[ny][nx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    v.assign(R, vector<char>(C));
    visit_idx.assign(R, vector<bool>(C));
    vector<bool> visit_alp('Z'-'A'+1);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char t;
            cin >> t;
            v[i][j] = t;
        }
    }
    visit_idx[0][0] = true;
    visit_alp.at(v[0][0]-'A') = true;
    dfs(0,0,visit_alp,1);
    cout << ans;

}