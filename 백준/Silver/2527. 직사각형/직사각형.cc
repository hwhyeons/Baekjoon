#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

class XY {
public:
    int x,y;
    bool is_first_rect;
    XY(int x, int y, bool is_first_rect) : x(x), y(y), is_first_rect(is_first_rect) {}
};


bool compare_x(XY& c1, XY& c2) {
    return c1.x < c2.x;
}

bool compare_y(XY& c1, XY& c2) {
    return c1.y < c2.y;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 4; ++i) {
        int sx1,sy1,ex1,ey1,sx2,sy2,ex2,ey2;
        cin >> sx1>>sy1>>ex1>>ey1>>sx2>>sy2>>ex2>>ey2;
        XY c1(sx1,sy1,true);
        XY c2(ex1,ey1,true);
        XY c3(sx2,sy2,false);
        XY c4(ex2,ey2,false);
        vector<XY> xvector={c1,c2,c3,c4};
        vector<XY> yvector={c1,c2,c3,c4};
        sort(xvector.begin(),xvector.end(),compare_x);
        sort(yvector.begin(),yvector.end(),compare_y);

        bool x_is_point = false; // 선으로 겹치는 경우
        if (xvector[0].is_first_rect == xvector[1].is_first_rect) { // 안겹치거나 맞닿아 있거나
            if (xvector[1].x == xvector[2].x) {
                x_is_point = true;
            } else {
                cout << "d\n";
                continue;
            }
        } else {
            if (xvector[1].x == xvector[2].x) {
                x_is_point = true;
            }
        }

        bool y_is_point = false; // 선으로 겹치는 경우
        if (yvector[0].is_first_rect == yvector[1].is_first_rect) { // 안겹치거나 맞닿아 있거나
            if (yvector[1].y == yvector[2].y) {
                y_is_point = true;
            } else {
                cout << "d\n";
                continue;
            }
        } else {
            if (yvector[1].y == yvector[2].y) {
                y_is_point = true;
            }
        }

        if (x_is_point && y_is_point) {
            cout << "c\n";
        } else if (x_is_point || y_is_point) {
            cout << "b\n";
        } else {
            cout << "a\n";
        }
    }
}