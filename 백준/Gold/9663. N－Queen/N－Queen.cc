#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

ll cnt = 0;
int n;
vector<int> rc; // {행 - 퀸의 위치)

bool promising(int r, int c) {
    for (int i = 0; i < r; ++i) {
//        if (c == rc[i] || abs((rc[i]-c)/(i-r)) == 1) return false;
        if (c == rc[i] || abs(rc[i] - c) == abs(i - r)) return false;
    }
    return true;
}

void nqueen(int row) {
    for (int next_c = 0; next_c < n; ++next_c) {
        if (promising(row,next_c)) {
            rc[row] = next_c;
            if (row == n-1) {
                cnt++;
                continue;
            } else {
                nqueen(row+1);
            }
        }
    }
    rc[row] = -1;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rc.assign(n,-1);
    nqueen(0);
    cout << cnt;
}