
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

int next_group = 1;

int min_answer = 100000000;

int N;

void make_group(auto& v, auto& group_num);
void bfs(int y,int x,auto& group_num,auto& vst);

void find_best(auto& group_num,auto& vst) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (group_num[i][j] != 0) {
                bfs(i,j,group_num,vst);
            }
        }
    }
            
}




int main() {
    ios_base::sync_with_stdio(NULL);
    
    cin >> N;
    std::vector<vector<int>> v(N,vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> group_num(N,vector<int>(N));

    make_group(v,group_num);
    
    vector<vector<int>> vst(N,vector<int>(N));
    
    find_best(group_num,vst);
    
    cout << min_answer;
}

void dfs(auto& v, auto& group_num, int y,int x,int gn){
    group_num[y][x] = gn;
    for (int i =0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx <0 || nx >= N || ny>= N) continue;
        if (v[ny][nx] == 0)
            continue;
        if (group_num[ny][nx] != 0) continue;
        dfs(v,group_num,ny,nx,gn);
    }
}
    


void make_group(auto& v, auto& group_num){
    for (int i =0; i< N; i++ ){
        for (int j =0; j< N; j++ ){
            if (v[i][j] == 0) // 바다인 경우
                continue;
            if (group_num[i][j] != 0) {
                continue;
            }
            dfs(v,group_num,i,j,next_group);
            next_group+=1;            
        }
    }

}


int bfs_cnt = 1;
void bfs(int y,int x,auto& group_num,auto& vst){
    bfs_cnt++;
    int cur_group = group_num[y][x];
    deque<tuple<int,int,int>> d;
    d.push_front({y,x,0});
    vst[y][x] = bfs_cnt;
    bool flag = false;
    while (!d.empty()) {
        auto [cur_y,cur_x,dist] = d.front(); d.pop_front();
        if (flag) break;
        for (int i = 0; i < 4; i++) {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if (ny < 0 || nx <0 || nx >= N || ny>= N) continue;
            if (group_num[ny][nx] != 0) {
                if (group_num[ny][nx] != cur_group) { // 육지긴 한데 같은 육지
                    min_answer = min(min_answer,dist);
                    flag = true;
                    break;
                }
            } else { // 바다인 경우
                if (vst[ny][nx] == bfs_cnt) // 이미 방문한 바다
                    continue;
                vst[ny][nx] = bfs_cnt;
                d.push_back({ny,nx,dist+1});
            }
        }
    }
}






