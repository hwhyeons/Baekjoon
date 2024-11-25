#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
typedef long long ll;
using namespace std;

// -----------------------------------------
// -----------------------------------------
// -----------------------------------------

class Node {
public:
    int y;
    int x;
    int crashCnt; // 부순 횟수
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> v(n,vector<char>(n));
    vector<vector<bool>> visit(n,vector<bool>(n));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    deque<Node> dq;
    dq.push_back({ 0,0,0 });
    visit[0][0] = true;
    while (!dq.empty()) {
        auto [y, x, crashCnt] = dq.front(); dq.pop_front();
        if (y == n - 1 && x == n - 1) {
            cout << crashCnt;
            return 0;
        }
        for (size_t i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visit[ny][nx]) continue;
            visit[ny][nx] = true;
            if (v[ny][nx] == '0') { // 벽
                dq.push_back({ ny,nx,crashCnt + 1 });
            } else {
                dq.push_front({ ny,nx,crashCnt });
            }
        }
    }


    return 0;
}