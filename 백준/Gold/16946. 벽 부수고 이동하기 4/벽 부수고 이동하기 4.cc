#include <bits/stdc++.h>
#include <ranges>

typedef long long ll ;

using namespace std;
vector<vector<char>> v;
vector<vector<ll>> ans;
vector<vector<bool>> vis;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

class Group {
public:
    int group_idx;
    ll member_cnt = 0; // 멤버 수
};

vector<vector<int>> group; // 특정 좌표에서의 group번호
vector<Group> vg; // 그룹 정보를 포함하는 벡터

void grouping(Group& new_group,int y, int x) {
    vis[y][x] = true;
    group[y][x] = new_group.group_idx;
    new_group.member_cnt+=1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny <0 || nx >= v[0].size() || ny >= v.size()) continue;
        if (v[ny][nx] == '1') continue;
        if (vis[ny][nx]) continue;
        grouping(new_group,ny,nx);
    }
}

int next_group_id = 0;
ll get_cnt(int y, int x) {
    ll acc = 1;
    vector<int> check_group;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny <0 || nx >= v[0].size() || ny >= v.size()) continue;
        if (v[ny][nx] == '1') continue;
        if (group[ny][nx] != -1) { // 그룹이 있는 경우
            int group_number = group[ny][nx];
            // 아직 검사 안한 그룹
            if (find(check_group.begin(), check_group.end(),group_number) == check_group.end()) {
                check_group.push_back(group_number);
                acc += vg[group_number].member_cnt;
            } else { // 이미 검사한 그룹이면 넘기기
                continue;
            }
        } else {
            // 그룹이 없는 경우 그룹화 작업시작
            Group new_group;
            new_group.group_idx = next_group_id++;
            grouping(new_group,ny,nx);
            int group_member_count = new_group.member_cnt;
            acc+=group_member_count;
            vg.push_back(new_group);
            check_group.push_back(new_group.group_idx);
        }
    }
    return acc;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    v.assign(N,vector<char>(M));
    ans.assign(N,vector<ll>(M));
    vis.assign(N,vector<bool>(M));
    group.assign(N,vector<int>(M,-1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] == '0') {
                cout << 0;
                continue;
            } else { // 벽인 경우
                ll cnt = get_cnt(i,j);
                cout << cnt%10;
            }
        }
        cout << "\n";
    }

}