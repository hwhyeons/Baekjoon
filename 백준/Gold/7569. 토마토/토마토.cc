#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;
vector<vector<vector<int>>> v;
vector<vector<vector<int>>> refresh_time;
int cur_time = 0;

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
int M,N,H;

class Cd {
public:
    int z,y,x,time;
    Cd(int z, int y, int x,int time) : z(z),y(y),x(x),time(time) {}
};

int dfs(int z, int y, int x) {
    int cascade_cnt = 0;
    refresh_time[z][y][x] = cur_time;
    for (int i = 0; i < 6; ++i) {
        int nz = z+dz[i];
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (nz < 0 || ny < 0 || nx < 0) continue;
        if (nz >= H || ny >= N || nx >= M) continue;
        if (v[nz][ny][nx] != 0) continue;
        if (refresh_time[nz][ny][nx] == cur_time) continue; // 이미 갱신
        v[nz][ny][nx] = 1;
        cascade_cnt+=1;
        refresh_time[nz][ny][nx] = cur_time;
    }
    return cascade_cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>M>>N>>H;
    v.assign(H,vector<vector<int>>(N,vector<int>(M)));
    refresh_time.assign(H,vector<vector<int>>(N,vector<int>(M,-1)));

    queue<Cd> q;

    int left_cnt = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                int t;
                cin >> t;
                v[i][j][k] = t;
                if (t == 1) {
                    q.push(Cd(i,j,k,0));
                } else if (t == 0) {
                    left_cnt++;
                }
            }
        }
    }

    int cur_time = 0;
    while (!q.empty()) {
        Cd coor = q.front(); q.pop();
        int z = coor.z;
        int y = coor.y;
        int x = coor.x;
        int time = coor.time;
        cur_time = max(time,cur_time);
        for (int i = 0; i < 6; ++i) {
            int nz = z+dz[i];
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (nz < 0 || ny < 0 || nx < 0) continue;
            if (nz >= H || ny >= N || nx >= M) continue;
            if (v[nz][ny][nx] != 0) continue;
            if (refresh_time[nz][ny][nx] == cur_time) continue; // 이미 갱신
            v[nz][ny][nx] = 1;
            left_cnt--;
            refresh_time[nz][ny][nx] = time;
            q.push(Cd(nz,ny,nx,time+1));
        }
    }

    // 반복문 끝났는데 아직 남은 경우
    if (left_cnt > 0) {
        cout << -1;
    } else {
        cout << cur_time;
    }
}