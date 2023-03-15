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



struct compare{
    bool operator()(tuple<int,int,int>& t1, tuple<int,int,int>& t2) {
        if (get<2>(t1) > get<2>(t2)) {
            return true;
        } else return false;
    }
};


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool is_adj(vector<vector<string>>& v,int y, int x) {
    int nx,ny;
    for (int i =0; i<4; i++) {
        nx = x+dx[i];
        ny = y+dy[i];
        if (nx < 0 || ny <0 || nx>=v[0].size() || ny>=v.size()) continue;
        if (v[ny][nx] == "#") return true; // 하나라도 벽에 인접한 경우
    }
    return false;
}
void bfs(vector<vector<string>>& v, vector<vector<int>>& v_time,int start_x, int start_y) {
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,compare> q; // (x,y,time)
    q.push({start_x,start_y,0});
    while (!q.empty()) {
        auto tp = q.top();
        q.pop();
        int x = get<0>(tp);
        int y = get<1>(tp);
        int time = get<2>(tp);
        if (time >= v_time[y][x]) continue;
        else v_time[y][x] = time;

        bool this_is_adj = is_adj(v,y,x);
        int nx,ny;
        for (int i =0; i<4; i++) {
            nx = x+dx[i];
            ny = y+dy[i];
            if (nx < 0 || ny <0 || nx>=v[0].size() || ny>=v.size()) continue;
            if (v[ny][nx] == "#") continue;  // 벽에 인접한 칸으로 이동 (벽으로 이동하는게 아님)
            if (this_is_adj && is_adj(v,ny,nx)) { // 인접칸에서 인접칸으로 이동
                q.push({nx,ny,time});
            } else {
                q.push({nx,ny,time+1});
            }
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h,w;
    cin >> h >> w;
    vector<vector<string>> v(h,vector<string>(w));
    vector<vector<int>> time(h,vector<int>(w,INT_MAX));
    
    string t;
    int start_x,start_y,end_x,end_y;
    for (int i =0; i<h; i++) {
        cin >> t;
        for (int j =0; j<w; j++) {
            v[i][j] = t.substr(j,1);
            if (v[i][j] == "S") {
                start_x = j;
                start_y = i;
            } else if (v[i][j] == "E") {
                end_x = j;
                end_y = i;
            }
        }
    }

    bfs(v,time,start_x,start_y);
    cout << time[end_y][end_x];
    
}