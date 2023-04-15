#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

double a,b;
double c,d;

bool l1_inf;
bool l2_inf;

double x1,y1_,x2,y2;
double x3,y3,x4,y4;

// 1번 직선의 방정식
double f1(int x) {
    // y = ax + b
    return a*x+b;
//    if (l1_inf) {
//        return x1;
//    } else {
//        return a*x+b;
//    }
}

// 2번 직선의 방정식
double f2(int x) {
//    if (l2_inf) {
//        return x3;
//    }
    // y = cx + d
    return c*x+d;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x1 >> y1_ >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    if (x1 > x2) {
        swap(x1,x2);
        swap(y1_,y2);
    }
    if (x3 > x4) {
        swap(x3,x4);
        swap(y3,y4);
    }
    l1_inf = (ll)x2-(ll)x1 == 0;
    l2_inf = (ll)x4-(ll)x3 == 0;
    bool l1_0 = (ll)y2-(ll)y1_ == 0;
    bool l2_0 = (ll)y4-(ll)y3 == 0;

    // 둘다 무한대 기울기
    if (l1_inf && l2_inf) {
        cout << 0;
        return 0;
    } else if (l1_0 && l2_0) {
        cout << 0;
        return 0;
    }

    // 하나 무한대 하나 90도
    if (l1_inf && l2_0) {
        if ((x3 > x1 && x4 > x1) || (x3 < x1 && x4 < x1)) {
            cout << 0;
            return 0;
        }
        if ((y1_ > y3 && y2 > y3) || (y1_ < y3 && y2 < y3)) {
            cout << 0;
            return 0;
        }
        cout << 1;
        return 0;
    } else if (l2_inf && l1_0) {
        swap(x1,x3);
        swap(x2,x4);
        swap(y1_,y3);
        swap(y2,y4);
        if ((x3 > x1 && x4 > x1) || (x3 < x1 && x4 < x1)) {
            cout << 0;
            return 0;
        }
        if ((y1_ > y3 && y2 > y3) || (y1_ < y3 && y2 < y3)) {
            cout << 0;
            return 0;
        }
        cout << 1;
        return 0;
    }
    // 둘중 하나가 무한대 기울기
    if (l1_inf || l2_inf) {
        if (l2_inf) {
            swap(x1, x3);
            swap(y1_, y3);
            swap(x2, x4);
            swap(y2, y4);
        }
        if ((x3 > x1 && x4 > x1) || (x3 < x1 && x4 < x1)) {
            cout << 0;
            return 0;
        }
        c = (y4-y3)/(x4-x3);
        d = -x3*((y4-y3)/(x4-x3))+y3;
        double fn = f2(x1);
        if ((fn > max(y1_,y2) && fn > min(y1_,y2)) || (fn < max(y1_,y2) && fn < min(y1_,y2))) {
            cout << 0;
            return 0;
        }
        cout << 1;
        return 0;
    }


    // 둘중 하나가 무한대면 스왑
//    if (l1_inf || l2_inf) {
//        swap(x1,x3);
//        swap(y1_,y3);
//        swap(x2,x4);
//        swap(y2,y4);
//    }
    a = (y2-y1_)/(x2-x1);
    b = -x1*((y2-y1_)/(x2-x1))+y1_;
    c = (y4-y3)/(x4-x3);
    d = -x3*((y4-y3)/(x4-x3))+y3;

    bool ans1 = f2(x3) > f1(x3);
    bool ans2 = f2(x4) > f1(x4);
    bool ans3 = f2(x1) > f1(x1); // 교차하더라도 안만날 수 있음
    bool ans4 = f2(x2) > f1(x2);
    if (ans1 != ans2 && ans3 != ans4) {
        cout << 1;
    } else {
        cout << 0;
    }



}