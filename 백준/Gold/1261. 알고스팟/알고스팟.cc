
#include <bits/stdc++.h>

using namespace std;


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
void dfs(auto& v, auto& ans, int y, int x, int before){

    for (int i =0; i<4;i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny>=v.size() || nx>=v[0].size() || ny<0 || nx <0) continue;
        if (v[ny][nx]=='1') {
            if (ans[ny][nx] >= before+2) {
                ans[ny][nx] = before+1;
                v[ny][nx] = '0';
                dfs(v,ans,ny,nx,before+1);
                v[ny][nx] = '1';
            }
        } else {
            if (ans[ny][nx] >= before+1) {
                ans[ny][nx] = before;
                dfs(v,ans,ny,nx,before);
            }
        }
    }
}

int main()
{
    cin.tie(0);
	int N,M;
    cin >> M >> N;
    vector<vector<char>> v(N,vector<char>(M));
    vector<vector<int>> ans(N,vector<int>(M,100000000));
    ans[0][0]=0;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }
    dfs(v,ans,0,0,0);
    cout << ans[N-1][M-1];
	return 0;
}