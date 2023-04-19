#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

double a,b;
double c,d;

bool l1_inf;
bool l2_inf;



// 1번 직선의 방정식
double f1(int x) {
    // y = ax + b
    return a*x+b;
}

// 2번 직선의 방정식
double f2(int x) {
    return c*x+d;
}


// 1점과 2점 사이에 3점이 있는 경우
bool is_inside(double x1, double y1, double x2, double y2, double x3, double y3) {
    if (x1 > x2) throw "not x2 > x1";
    double dxdy1 = (y2-y1)/(x2-x1);
    double dxdy2 = (y2-y3)/(x2-x3);
    double dxdy3 = (y3-y1)/(x3-x1);
    if ((dxdy1 == dxdy2) && (dxdy2 == dxdy3)) {
        if (x3 >= x1 && x3 <= x2) {
            if (y3 >= min(y1,y2) && y3 <= max(y1,y2)){
                return true;
            }
        }
    }
    return false;
}

bool contains_same_coordinate(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    // 한 점이라도 동일한 좌표가 있는 경우 ㄱ자 처럼 한점이랑 겹치면서 90도
    vector<pair<int,int>> tmp_v;
    tmp_v.push_back(make_pair((int)x1,(int)y1));
    tmp_v.push_back(make_pair((int)x2,(int)y2));
    tmp_v.push_back(make_pair((int)x3,(int)y3));
    tmp_v.push_back(make_pair((int)x4,(int)y4));
    set<pair<int, int>> tmp_s(tmp_v.begin(), tmp_v.end());
    // 겹치는 좌표가 존재한다면 무조건 교차
    if (tmp_s.size() != tmp_v.size()) {
        return true;
    } else{
        return false;
    }
}


// x1,y1,x2,y2가 하나의 선분을 이루고  x3,y3,x4,y4가 하나의 선분을 이룸
bool is_cross_segment(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {

    // "두번째" 선분이 선이 아니라 점인 경우
    // 1번 선분 사이에 (x3,y3)가 위치하면 됨
    if ((x3 == x4 && y3 == y4)) {
        return is_inside(x1,y1,x2,y2,x3,y3);
    }

    // 동일한 좌표가 존재하면 교차로 판정
    bool is_same_coor = contains_same_coordinate(x1,y1,x2,y2,x3,y3,x4,y4);
    if (is_same_coor) {
        return true;
    }

    // x1이 작은 쪽으로 좌표를 정렬
    if (x1 > x2) {
        swap(x1,x2);
        swap(y1, y2);
    }
    if (x3 > x4) {
        swap(x3,x4);
        swap(y3,y4);
    }

    // 4개 중에 세점이 모두 일직선 상에 있는 경우를 모두 찾기

    // 기울기가 무한대인 경우랑 0인 경우는 특수 케이스로 분류
    l1_inf = (ll)x2-(ll)x1 == 0;
    l2_inf = (ll)x4-(ll)x3 == 0;
    bool l1_0 = (ll)y2-(ll)y1 == 0;
    bool l2_0 = (ll)y4-(ll)y3 == 0;

    // 둘다 무한대 / 둘다 0 / 하나만 무한대 / 하나만 0인 경우에도 일직선 판별 필요;

    // 둘다 무한대 기울기
    if (l1_inf && l2_inf) {
        // x좌표가 다르면 틀림
        if (x1 != x3) {
            return false;
        }

        // 선분이 일직선 위에 있거나 한점이 겹치는 경우
        if (max(y1,y2) < min(y3,y4) || max(y3,y4) < min(y1,y2)) {
            return false;
        } else {
            return true;
        }
    } else if (l1_0 && l2_0) {
        // y좌표가 다르면 틀림
        if (y1 != y3) {
            return false;
        }

        // 선분이 일직선 위에 있거나 한점이 겹치는 경우
        if (max(x1,x2) < min(x3,x4) || max(x3,x4) < min(x1,x2)) {
            return false;
        } else {
            return true;
        }
    }


    // 하나 무한대 하나 90도
    //
    if ((l1_inf && l2_0) || (l2_inf && l1_0)) {
        // l2_inf는 l1_inf로 좌표 스왑후 동일하게
        if (l2_inf && l1_0) {
            swap(x1,x3);
            swap(x2,x4);
            swap(y1, y3);
            swap(y2,y4);
        }

        if ((x3 > x1 && x4 > x1) || (x3 < x1 && x4 < x1)) {
            return false;
        }
        if ((y1 > y3 && y2 > y3) || (y1 < y3 && y2 < y3)) {
            return false;
        }
        return true;
    }

    // 둘중 하나가 무한대 기울기
    if (l1_inf || l2_inf) {

        // l1_inf인 경우랑 l2_inf인 경우랑 좌표만 바뀌고 동일하므로 기울기 무한선분을 l1_inf로 고정
        if (l2_inf) {
            swap(x1, x3);
            swap(y1, y3);
            swap(x2, x4);
            swap(y2, y4);
        }
        if ((x3 > x1 && x4 > x1) || (x3 < x1 && x4 < x1)) {
            return false;
        }
        c = (y4-y3)/(x4-x3);
        d = -x3*((y4-y3)/(x4-x3))+y3;
        double fn = f2(x1);
        if ((fn > max(y1, y2) && fn > min(y1, y2)) || (fn < max(y1, y2) && fn < min(y1, y2))) {
            return false;
        }
        return true;
    }

    a = (y2 - y1) / (x2 - x1);
    b = -x1*((y2 - y1) / (x2 - x1)) + y1;
    c = (y4-y3)/(x4-x3);
    d = -x3*((y4-y3)/(x4-x3))+y3;


//    세점이 한선분 위에 있는데, 겹치는게 아니라 선분 사이에 존재하는 모든 경우;
//    기울기가 무한대가 나오는 경우는 이미 제거했으므로 DIVIDE 0 고려 X;
    bool ok1 = is_inside(x1,y1,x2,y2,x3,y3);
    bool ok2 = is_inside(x1,y1,x2,y2,x4,y4);
    bool ok3 = is_inside(x3,y3,x4,y4,x1,y1);
    bool ok4 = is_inside(x3,y3,x4,y4,x2,y2);
    if (ok1 || ok2 || ok3 || ok4) {
        return true;
    }

    // 교차 판별
    bool ans1 = f2(x3) > f1(x3);
    bool ans2 = f2(x4) > f1(x4);
    bool ans3 = f2(x1) > f1(x1); // 교차하더라도 안만날 수 있음
    bool ans4 = f2(x2) > f1(x2);
    if (ans1 != ans2 && ans3 != ans4) {
        return true;
    } else {
        return false;
    }
}

// 직사각형의 두 모서리 좌표
bool is_inside_rectangle(int line_x1, int line_y1, int line_x2, int line_y2,int rx1,int ry1,int rx2,int ry2) {
    // 겹치는 경우도 true
    if (max(line_y1,line_y2) <= max(ry1,ry2) && min(line_y1,line_y2) >= min(ry1,ry2)) {
        if (max(line_x1,line_x2) <= max(rx1,rx2) && min(line_x1,line_x2) >= min(rx1,rx2)) {
            return true;
        }
    }
    return false;

}


/*
 * 같은 점 위에 있는지 판별할 때, 함수값 비교시 double타입이라 틀릴 수도 있음
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t_cnt;
    cin >> t_cnt;

    while (t_cnt--) {
        double x1,y1,x2,y2;
        double rx1,ry1,rx2,ry2,rx3,ry3,rx4,ry4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> rx1 >> ry1 >> rx2 >> ry2;
        if (rx1 > rx2) { // rx1이 작은쪽으로
            swap(rx1,rx2);
            swap(ry1,ry2);
        }
        // 4개의 좌표로 변경;
        rx3 = rx1;
        ry3 = ry2;
        rx4 = rx2;
        ry4 = ry1;

        // 직사각형 안에 선분이 있는 경우
        if (is_inside_rectangle(x1,y1,x2,y2,rx1,ry1,rx2,ry2)) {
            cout << "T" << "\n";
            continue;
        }

        // 직사각형으로 총 4개의 선분 만들 수 있음
        bool cross1 = is_cross_segment(x1, y1, x2, y2, rx1, ry1, rx3, ry3);
        bool cross2 = is_cross_segment(x1, y1, x2, y2, rx1, ry1, rx4, ry4);
        bool cross3 = is_cross_segment(x1, y1, x2, y2, rx2, ry2, rx3, ry3);
        bool cross4 = is_cross_segment(x1, y1, x2, y2, rx2, ry2, rx4, ry4);

        // 선
        if (cross1 || cross2 || cross3 || cross4) {
            cout << "T" << "\n";
            continue;
        } else {
            cout << "F" << "\n";
            continue;
        }
    }
    return 0;
}