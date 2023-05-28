#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n; cin >> m >> n;
    int x=0,y=0;
    int dx = 1;
    int dy = 0;
    int nx,ny;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "MOVE") {
            int dm;
            cin >> dm;
            x += dm*dx;
            y += dm*dy;
            if (x < 0 || y < 0 || x >= m|| y>=m) {
                cout << "-1";
                return 0;
            }
        } else { // "TURN"
            int dir;
            cin >> dir;
            if (dir == 0) { // 왼쪽으로 90도
                nx = (int)(dx*cos(M_PI/2) - dy*sin(M_PI/2));
                ny = (int)(dx*sin(M_PI/2) + dy*cos(M_PI/2));
                dx = nx;
                dy = ny;
            } else { // dir == 1
                nx = (int)(dx*cos(-M_PI/2) - dy*sin(-M_PI/2));
                ny = (int)(dx*sin(-M_PI/2) + dy*cos(-M_PI/2));
                dx = nx;
                dy = ny;
            }
        }
    }
    cout << x << " " << y;
}