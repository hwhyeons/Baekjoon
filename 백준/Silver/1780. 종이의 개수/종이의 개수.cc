#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;



vector<vector<int>> v;
bool getOk(int y, int x, int size) {
    if (size == 1) return true;
    int first = v[y][x];
    for (int i = y; i < y+size; ++i) {
        for (int j = x; j < x+size; ++j) {
            if (v.at(i).at(j) == first) continue;
            else return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    v.assign(n,vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }

    int minus1 = 0;
    int zero = 0;
    int plus1 = 0;

    // (y,x,한 변의 길이)
    queue<tuple<int,int,int>> q;
    q.emplace(0,0,n);
    while (!q.empty()) {
        auto [y,x,size] = q.front();
        q.pop();
        bool is_all_ok = getOk(y,x,size);
        if (is_all_ok) {
            if (v[y][x] == -1) {
                minus1++;
            } else if (v[y][x] == 0) {
                zero++;
            } else {
                plus1++;
            }
        } else {
            int newSize = size/3;
            q.emplace(y,x,newSize);
            q.emplace(y+newSize,x,newSize);
            q.emplace(y+newSize*2,x,newSize);
            q.emplace(y,x+newSize,newSize);
            q.emplace(y+newSize,x+newSize,newSize);
            q.emplace(y+newSize*2,x+newSize,newSize);
            q.emplace(y,x+newSize*2,newSize);
            q.emplace(y+newSize,x+newSize*2,newSize);
            q.emplace(y+newSize*2,x+newSize*2,newSize);
        }
    }
    cout << minus1 << "\n" << zero << "\n" << plus1;
}