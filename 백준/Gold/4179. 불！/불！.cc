#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int R,C;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


//class Person {
//public:
//    int y,x,b_y,b_x;
//    int time;
//};

bool can_out(vector<vector<char>>& v, int& y, int& x) {
    if (y == R-1 || x == C-1 || y == 0 || x == 0) {
        return true;
    } else {
        return false;
    }
}

set<pair<int,int>> next_fire;
void expand_fire(vector<vector<char>>& v, vector<vector<int>>& v_time, const int& cur_time) {
    set<pair<int,int>> nn;
    for (auto& pa : next_fire) {
        v_time[pa.first][pa.second] = cur_time;
        for (int k = 0; k < 4; ++k) {
            int nx = pa.second + dx[k];
            int ny = pa.first + dy[k];
            if (nx < 0 || ny < 0 || nx >= C || ny>=R) continue;
            if (v[ny][nx] == '#' || v[ny][nx] == 'F' || v_time[ny][nx] == cur_time) continue; // 옮겨붙을 곳이 아닌 경우
            nn.insert({ny,nx});
            v[ny][nx] = 'F';
            v_time[ny][nx] = cur_time;
        }
    }
    next_fire = nn;
}
// return : 불이 사람에게 붙는 경우
//void expand_fire(vector<vector<char>>& v, vector<vector<bool>>& visit,vector<vector<int>>& v_time, int& cur_time) {
//    for (int i = 0; i < R; ++i) {
//        for (int j = 0; j < C; ++j) {
//            if (v[i][j] == 'F' && !visit[i][j]) {
//                if (v_time[i][j] == cur_time) continue;
//                visit[i][j] = true;
//                v_time[i][j] = cur_time;
//                for (int k = 0; k < 4; ++k) {
//                    int nx = j + dx[k];
//                    int ny = i + dy[k];
//                    if (nx < 0 || ny < 0 || nx >= C || ny>=R) continue;
////                    if (v[ny][nx] == 'J') return true; // 사람한테 옮겨 붙는 경우
//                    if (v[ny][nx] == '#' || v[ny][nx] == 'F') continue; // 옮겨붙을 곳이 아닌 경우
////                    if (v_time[ny][nx] == cur_time) continue; // 방금 붙은 경우
//                    v[ny][nx] = 'F';
//                    v_time[ny][nx] = cur_time;
//                }
//            }
//        }
//    }
//    return;
//}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    int start_y,start_x;
    vector<vector<char>> v(R,vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 'J') {
                if (i == R-1 || j == C-1 || j ==0 || i == 0) {
                    cout << 1;
                    return 0;
                }
                start_y = i;
                start_x = j;
            } else if (v[i][j] == 'F'){
                next_fire.insert({i,j});
            }
        }
    }
    vector<vector<int>> v_time(R,vector<int>(C,-1));
    vector<vector<bool>> visit(R,vector<bool>(C));
    vector<vector<bool>> visit_person(R,vector<bool>(C));
    queue<tuple<int,int,int>*> q;
    tuple<int,int,int>* ptmp = new tuple<int,int,int>({start_y,start_x,0});
    q.push(ptmp);
    visit_person[start_y][start_x] = true;
    int before_time = 0;
    int continue_time = -1;
    while (!q.empty()) {
        tuple<int,int,int>* p = q.front(); q.pop();
        int cur_x = get<1>(*p);
        int cur_y = get<0>(*p);
        int cur_time = get<2>(*p);
        delete p;
        if (cur_time >= 1000005) break;
        if (cur_time != before_time) {
            before_time = cur_time;
            expand_fire(v,v_time,cur_time);
//            for (int i = 0; i < R; ++i) {
//                for (int z = 0; z < C; ++z) {
//                    cout << v[i][z] << " ";
//                }
//                cout << "\n";
//            }
//            cout << "\n";
        }
//        cout << cur_y << " " << cur_x << "\n";
        if (v[cur_y][cur_x] == 'F' || cur_time == continue_time) {
//            continue_time = cur_time;
            continue;
        } else {
            v[cur_y][cur_x] = 'J';
        }
        int nx,ny;
        for (int i = 0; i < 4; ++i) {
            nx = cur_x + dx[i];
            ny = cur_y + dy[i];
            if (nx < 0 || ny < 0 || nx>=C || ny>=R) continue;
            if (v[ny][nx] == 'F' || v[ny][nx] == '#' || visit_person[ny][nx]) continue;
            tuple<int,int,int>* tp = new tuple<int,int,int>({ny,nx,cur_time+1});
            visit_person[ny][nx] = true;
            q.push(tp);
        }
        if (can_out(v,cur_y,cur_x)) {
            cout << cur_time+1;
            return 0;
        }
        v[cur_y][cur_x] = '.';
    }
    cout << "IMPOSSIBLE";
}