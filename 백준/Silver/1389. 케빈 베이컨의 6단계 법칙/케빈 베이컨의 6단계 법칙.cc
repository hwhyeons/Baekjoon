#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <map>

#define ll long long

using namespace std;

vector<vector<bool>> connect;

int n,m;

// bfs
int go(int number_p) {
    vector<int> mins(n+1,INT_MAX);
    vector<bool> visit(n+1,false);
    mins[number_p] = 0;
    std::queue<pair<int,int>> q; // (node number, value)
    visit[number_p] = true;
    q.push({number_p,0});
    while (!q.empty()) {
        auto cur_pair = q.front(); q.pop();
        int cur_node = cur_pair.first;
        int cur_value = cur_pair.second;
        mins[cur_node] = cur_value;
        // check connected
        for (int i = 1; i < mins.size(); ++i) {
            if (visit[i]) continue;
            if (connect[cur_node][i]) {
                visit[i] = true;
                q.push({i,cur_value+1});
            }
        }
    }
//    mins[number_p] = INT_MAX; // 자기 자신이 최소가 나오면 안되므로 MAX로 변경
    int kevin = accumulate(mins.begin()+1,mins.end(),0); // 0번 인덱스 스킵
    return kevin;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    connect.assign(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < m; ++i) {
        int t1,t2; cin >> t1 >> t2;
        connect[t1][t2] = true;
        connect[t2][t1] = true;
    }
    int mn = INT_MAX;
    int ans_p = 0;
    // i : 사람 번호 (모든 사람 체크)
    for (int i = 1; i <= n; ++i) {
        vector<vector<bool>> visit(n+1,vector<bool>(n+1));
        int tmp = go(i); // 최소 길이
        if (tmp < mn) {
            ans_p = i;
            mn = tmp;
        }
    }
    cout << ans_p;

}
