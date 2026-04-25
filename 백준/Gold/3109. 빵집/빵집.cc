// #include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ranges>
#include<deque>
#include <limits>
#include <set>
#include <map>

typedef long long ll;
typedef long double ld;
using namespace std;
int R,C;
int answer= 0;

bool dfs(vector<vector<char>>& v,vector<vector<bool>>& visit,int row, int col) {
    if (row<0 || row>=R) return false;
    if (visit[row][col]) return false;
    if (v[row][col]=='x') return false;
    visit[row][col] = true;
    if (col==C-1) {
        answer++;
        return true;
    }
    if (dfs(v,visit,row-1,col+1)) return true;
    if (dfs(v,visit,row,col+1)) return true;
    if (dfs(v,visit,row+1,col+1)) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    vector<vector<char>> v(R,vector<char>(C));
    vector<vector<bool>> visit(R,vector<bool>(C));
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin >> v[i][j];
        }
    }

    for (int r = 0; r<R;r++) {
        dfs(v,visit,r,0);
    }
    cout << answer;


}