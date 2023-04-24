#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

vector<vector<char>> v;
vector<vector<bool>> vst;


vector<vector<int>> group_number;

int next_group = 1;

void dfs(int y, int x, vector<pair<int,int>>& cur_group) {
    cur_group.push_back({y,x});
    group_number[y][x] = next_group;
    vst[y][x] = true;
    char next_dir = v[y][x];
    int nx=x,ny=y;
    switch (next_dir) {
        case 'U':
            ny--;
            break;
        case 'D':
            ny++;
            break;
        case 'L':
            nx--;
            break;
        case 'R':
            nx++;
            break;
        default:
            throw "error";
    }
    if (group_number[ny][nx] != -1) {
        // cur_group에 있는 모든 y,x를 다 해당 group_number에 포함시키기;
        int merge_group = group_number[ny][nx];
        for (auto &pair: cur_group) {
            int my = pair.first;
            int mx = pair.second;
            group_number[my][mx] = merge_group;
        }
        return;
    } else {
        dfs(ny,nx,cur_group);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    v.assign(N, vector<char>(M));
    vst.assign(N, vector<bool>(M));
    group_number.assign(N, vector<int>(M,-1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
        }
    }
    group_number[0][0] = next_group++;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (vst[i][j]) continue;
            if (!(i == 0 && j == 0)) next_group++;
            vector<pair<int,int>> cur_group;
//            cur_group.push_back({i,j});
            dfs(i,j,cur_group);
        }
    }
    unordered_set<int> cnt_set; // 중복제거를 위한 set
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (group_number[i][j] == -1) continue;
            cnt_set.insert(group_number[i][j]);
        }
    }
    cout << cnt_set.size();

}