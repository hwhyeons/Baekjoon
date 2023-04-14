#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;
vector<vector<int>> prices;


int dx[] = {0,1,-1,0,0};
int dy[] = {0,0,0,1,-1};

pair<int,int> convert2xy(int idx) {
    int y = idx/prices.size();
    int x = idx%prices.size();
    return make_pair(x,y);
}

ll get_answer(int c1, int c2, int c3) {
    auto x1y1 = convert2xy(c1);
    auto x2y2 = convert2xy(c2);
    auto x3y3 = convert2xy(c3);
    int x1 = x1y1.first;
    int y1 = x1y1.second;
    int x2 = x2y2.first;
    int y2 = x2y2.second;
    int x3 = x3y3.first;
    int y3 = x3y3.second;
    vector<int> vx = {x1,x2,x3};
    vector<int> vy = {y1,y2,y3};
    vector<vector<bool>> visited(prices.size(),vector<bool>(prices.size()));

    ll acc = 0LL;
    for (int i = 0; i < vx.size(); ++i) {
        int xtmp = vx[i];
        int ytmp = vy[i];
        for (int j = 0; j < 5; ++j) {
            int nx = xtmp+dx[j];
            int ny = ytmp+dy[j];
            if (nx <0 || ny <0 || nx>=prices.size() || ny>=prices.size()) return LLONG_MAX;
            if (visited[ny][nx]) return LLONG_MAX;
            visited.at(ny).at(nx) = true;
            acc += prices.at(ny).at(nx);
        }
    }
    return acc;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    prices.assign(n,vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t; cin >> t;
            prices[i][j] = t;
        }
    }
    int max_idx = n*n-1;
    vector<int> idxs(max_idx+1);
    iota(idxs.begin(), idxs.end(),0);
    vector<bool> bo(max_idx+1);
    bo[0] = true;
    bo[1] = true;
    bo[2] = true;
    ll ans = LLONG_MAX;
    do {
        vector<int> selectedIndex;
        for (int i = 0; i < idxs.size(); ++i) {
            if (bo[i]) {
                selectedIndex.push_back(i);
            }
        }
        ans = min(ans,get_answer(selectedIndex.at(0),selectedIndex.at(1),selectedIndex.at(2)));
    } while(prev_permutation(bo.begin(), bo.end()));
    cout << ans;


}