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
#include <limits.h>

#define inf 2100000000
using namespace std;

int h,w;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};


class xy{
public:
    int x,y,t;
    xy(int y, int x,int t) : y(y),x(x),t(t){};
};

int mx = INT_MIN;
void bfs(vector<vector<int>>& v,vector<vector<bool>> &visit,int y1, int x1) {
    queue<xy> q;
    q.push({y1,x1,0});
    visit[y1][x1] = true;
    int time = 0;
    while(!q.empty()) {
        xy cur = q.front(); q.pop();
        int x = cur.x;
        int y = cur.y;
        int t = cur.t;
        time = max(t, time);
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx<0||ny<0||nx>=v[0].size()||ny>=v.size()) continue;
            if (v[ny][nx] == 0 || visit[ny][nx]) continue; // WATER
            q.push({ny,nx,t+1});
            visit[ny][nx] = true;
        }
    }
    mx = max(mx,time);
//    ans[y1][x1] = time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    vector<vector<int>>v(h,vector<int>(w)); // 0 : W / 1 : L

    for (int i =0; i<h; i++) {
        for (int j =0; j<w; j++) {
            char c;
            cin >> c;
            v[i][j] = c == 'L' ? 1 : 0;
        }
    }

    for (int i =0; i<h; i++) {
        for (int j =0; j<w; j++) {
            if (v[i][j] == 0) continue;
            vector<vector<bool>>visit(h,vector<bool>(w)); // 정답 배열
            bfs(v, visit,i, j);
        }
    }
    cout << mx;
    return 0;
}
