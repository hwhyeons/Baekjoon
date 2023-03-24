#include <algorithm>
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
#include <iostream>
#include <string>

using namespace std;
#define ll long long

vector<vector<int>> v;

int N,M;

class xy {
public:
    int x,y;
    xy(int y, int x) : y(y), x(x){}
    xy(){};
};

int mx = INT_MIN;



int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int get_part(vector<vector<int>>& v_copy) {
    int acc = 0;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            if (v_copy[i][j] == 0) {
                acc+=1;
            }
        }
    }
    return acc;
}

void cascade(vector<vector<int>>& v_copy, vector<vector<bool>>& visit, int y, int x) {
    visit[y][x] = true;
    v_copy[y][x] = 2; // 바이러스 감염
    for (int i = 0; i < 4; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || ny<0 || nx>=v[0].size() || ny>=v.size()) continue;
        if (visit[ny][nx] || v[ny][nx] == 1) continue; // 방문 또는 벽
        cascade(v_copy,visit,ny,nx);
    }
}


void copy_vector(vector<vector<int>>& v_copy) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            v_copy[i][j] = v[i][j];
        }
    }
}
void dfs_choose3(vector<xy>& v_empty,vector<xy>& out, int depth, int idx) {
    if (depth == 3) {
        // 뽑힌 세개를 벽으로
        for (int i = 0; i < 3; ++i) {
            int x = out[i].x;
            int y = out[i].y;
            v[y][x] = 1;
        }

        // 벡터 복사
        vector<vector<int>> v_copy(N,vector<int>(M));
        vector<vector<bool>> visit(N,vector<bool>(M));
        copy_vector(v_copy);

        // 전파 시키기
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (visit[i][j]) continue;
                if (v_copy[i][j] != 2)continue;
                cascade(v_copy,visit,i,j);
            }
        }

        // 영역 넓이
        int tmp = get_part(v_copy);
        mx = max(tmp,mx);

        // 원상 복귀
        for (int i = 0; i < 3; ++i) {
            int x = out[i].x;
            int y = out[i].y;
            v[y][x] = 0;
        }
        return;
    }

    for (int i = idx; i < v_empty.size(); ++i) {
        out[depth] = v_empty[i];
        dfs_choose3(v_empty,out,depth+1,i+1);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    v = vector<vector<int>>(N,vector<int>(M));
    vector<xy> v_empty;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 0) {
                v_empty.emplace_back(i,j);
            }
        }
    }
    vector<xy> out(3);
    dfs_choose3(v_empty,out,0,0);
    cout << mx;
}
