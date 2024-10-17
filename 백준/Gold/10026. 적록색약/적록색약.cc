#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;
// -----------------------------------------


int N;
unordered_set<int> visit;

int dxarr[] = { -1,1,0,0 };
int dyarr[] = { 0,0,1,-1 };

// diff : true면 구별
void dfs(vector<vector<char>>& v, int y, int x, bool diff) {
    int index = y * N + x;
    visit.insert(index);
    char curColor = v[y][x];
    for (int i = 0; i < 4; i++) {
        int dx = dxarr[i];
        int dy = dyarr[i];
        int ny = y + dy;
        int nx = x + dx;
        if (nx <0 || ny <0 || nx >= N || ny >= N) continue; // out of range
        if (visit.contains(ny * N + nx)) continue;
        char nextColor = v[ny][nx];
        if (diff && nextColor == curColor) { // 색약이 아닌 경우
            dfs(v, ny, nx, diff);
        } else if (!diff && (nextColor == curColor || (nextColor == 'R' && curColor == 'G') || (nextColor == 'G' && curColor == 'R'))) {
            dfs(v,ny,nx,diff);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<vector<char>> v(N, vector<char>(N));
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    int ans1 = 0;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            int index = i * N + j;
            if (visit.contains(index)) continue;
            dfs(v,i, j,true);
            ans1++;
        }
    }
    int ans2 = 0;
    visit.clear();
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            int index = i * N + j;
            if (visit.contains(index)) continue;
            dfs(v, i, j, false);
            ans2++;
        }
    }
    cout << ans1 << " " << ans2;
}