#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;
vector<pair<double,double>> v;

double ccw(double x1,double y1, double x2,double y2, double x3,double y3) {
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}

double minGap = LLONG_MAX;
double a1,a2;
void calArea(int s, int e){
    vector<pair<double,double>> area1;
    vector<pair<double,double>> area2;
    for (int i = 0; i < v.size(); ++i) {
        if (i == s || i == e) {
            area1.push_back(v.at(i));
            area2.push_back(v.at(i));
        }
        if (i < s || i > e) {
            area1.push_back(v.at(i));
        } else if (i > s || i < e) {
            area2.push_back(v.at(i));
        }
    }

    double acc1 = 0;
    double acc2 = 0;

    double baseX = area1.front().first;
    double baseY = area1.front().second;
    for (int i = 1; i <= area1.size()-2; ++i) {
        double x1 = area1.at(i).first;
        double y1 = area1.at(i).second;
        double x2 = area1.at(i+1).first;
        double y2 = area1.at(i+1).second;
        acc1 += ccw(baseX,baseY,x1,y1,x2,y2);
    }
    acc1 = abs(acc1);

    baseX = area2.front().first;
    baseY = area2.front().second;
    for (int i = 1; i <= area2.size()-2; ++i) {
        double x1 = area2.at(i).first;
        double y1 = area2.at(i).second;
        double x2 = area2.at(i+1).first;
        double y2 = area2.at(i+1).second;
        acc2 += ccw(baseX,baseY,x1,y1,x2,y2);
    }
    acc2 = abs(acc2);

    double gap = abs(acc1-acc2);

    if (gap < minGap) {
        minGap = gap;
        a1 = 0.5*acc1;
        a2 = 0.5*acc2;
        if (a1 > a2) {
            swap(a1,a2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double x,y;
    double bx,by; // 직전 좌표

    // 1번
    cin >> x >> y;
    v.push_back({x,y});


    // 1번과 2번 사이와 2번 ~
    for (int i = 0; i < 3; ++i) {
        cin >> x >> y;
        bx = v.back().first;
        by = v.back().second;
        v.push_back({(x+bx)/2,(y+by)/2});
        v.push_back({x,y});
    }

    // 맨마지막과 첫번째의 중앙
    bx = v.front().first; // front
    by = v.front().second;
    double tx = v.back().first;
    double ty = v.back().second;
    v.push_back({(tx+bx)/2,(ty+by)/2});

    // 두점을 골라서 CCW -> 바로 인접한 점은 제외
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i+2; j < v.size(); ++j) {
            calArea(i,j);
        }
    }


    cout << fixed;
    cout.precision(3);
    cout << a1 << " " << a2;
}