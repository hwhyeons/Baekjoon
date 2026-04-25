#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

double getRad(double d1, double d2, double d3) {
//    세선분 1,2,3에서 1과2가 이루는 사잇각 -> 코사인법칙이용;
//    주의!! 사잇각을 구하고 싶은 부분을 1,2번 인자로넘기기;
    double cos3 = (d1*d1 + d2*d2 - d3*d3) / (2*d1*d2);
    double degree = acos(cos3);
    return degree;
}

// 반지름과 각도
double getSector(double r, double rad) {
    return 0.5*r*r*rad; // 1/2 x r^2 x 세타
}


// 반지름과 각도
double getTriAreaWithRad(double r, double rad) {
    return 0.5*r*r*sin(rad);
}

double getLargeArea(double x1,double y1,double r1,double x2,double y2,double r2, double dist) {
    // 큰 반지름을 r2로 가정하고 작성
    if (r1 > r2) {
        swap(r1,r2);
        swap(x1,x2);
        swap(y1,y2);
    }

    double radBig_half = getRad(r2,dist,r1);
    double radSmall_half = getRad(r1,dist,r2);

    double radBig = radBig_half*2;
    double radSmall = (numbers::pi - radSmall_half)*2;

    double sectorBig = getSector(r2,radBig);
    double tirBig = getTriAreaWithRad(r2,radBig);
    double ans1 = sectorBig-tirBig;

    double smallCircle = r1*r1*numbers::pi;
    double sectorObtuse = smallCircle - getSector(r1,radSmall); // 둔각 부채꼴
    double smallTri = getTriAreaWithRad(r1,radSmall);
    double ans2 = sectorObtuse + smallTri;

    return ans1+ans2;

}

double getSmallArea(double x1,double y1,double r1,double x2,double y2,double r2, double dist) {
//    겹치는 상황에서 넓이 (포함관계X)
    double rad1= getRad(r1,dist,r2);
    double rad2= getRad(r2,dist,r1);

    // 코사인 법칙으로 구한 한 각은 1/2배인 각
    rad1 *= 2;
    rad2 *= 2;

    // 부채꼴의 넓이
    double sector1 = getSector(r1,rad1);
    double sector2 = getSector(r2,rad2);

    // 삼각형의 넓이
    double tri1 = getTriAreaWithRad(r1,rad1);
    double tri2 = getTriAreaWithRad(r2,rad2);

    double answer = (sector1 - tri1) + (sector2 - tri2);
    return answer;
}


double getDistTwoPoint(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double getCircleArea(double r) {
    return r*r*numbers::pi;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double x1,y1,r1,x2,y2,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    cout << fixed;
    cout.precision(3);
    // 원의 겹치는 형태 확인
    double dist = getDistTwoPoint(x1,y1,x2,y2);
    if (dist >= r1+r2) {
        cout << "0.000";
        return 0;
    } else if (r1+r2 > dist && (dist > max(r1,r2) - min(r1,r2))) {
        // 둔각 : 한 원의 중심 점이 다른 원 내부에 있는 경우
        if (max(r1,r2) > dist) {
            double answer = getLargeArea(x1,y1,r1,x2,y2,r2,dist);
            cout << answer;
        } else { // 예각으로 겹치는 경우
            double answer= getSmallArea(x1,y1,r1,x2,y2,r2,dist);
            cout << answer;
        }
    } else {
        // 포함 관계
        double minR = min(r1,r2);
        double area = getCircleArea(minR);
        cout << area;
    }
}