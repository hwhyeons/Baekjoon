#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;



int getDist(int x1,int y1,int x2,int y2) {
     return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int xs,ys,xe,ye,dx,dy;
    cin >> xs >> ys >> xe >> ye >> dx >> dy;
    int curX = xe;
    int curY = ye;

    int lc = gcd(dx,dy);
    dx /= lc;
    dy /= lc;

    tuple<int,int,int> mntp{-200,-200,INT_MAX}; // x,y,min
    while (true) {
        auto [minx,miny,mn] = mntp;
        int dist = getDist(curX,curY,xs,ys);
        if (dist < mn) {
            mntp = {curX,curY,dist};
        } else { // 점점 커지는 방향으로 진행한다면 종료
            break;
        }
        curX += dx;
        curY += dy;
//        if (((curX > 100 || curX < -100)) && ((curY > 100 || curY < -100))
        if (dx == 0 && dy == 0) break;
    }
    auto& [a1,a2,a3] = mntp;
    cout << a1 << " " << a2;



}