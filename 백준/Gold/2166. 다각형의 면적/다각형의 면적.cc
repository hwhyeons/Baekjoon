#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

double ccw(double x1,double y1, double x2,double y2, double x3,double y3) {
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> xyv;
    for (int i = 0; i < n; ++i) {
        int t1,t2;
        cin >> t1 >> t2;
        xyv.push_back({t1,t2});
    }
    double acc = 0ll;
    int startX = xyv.front().first;
    int startY = xyv.front().second;
    for (int i = 1; i <= xyv.size()-2; ++i) {
        int x2 = xyv.at(i).first;
        int y2 = xyv.at(i).second;
        int x3 = xyv.at(i+1).first;
        int y3 = xyv.at(i+1).second;
        acc += ccw(startX,startY,x2,y2,x3,y3);
    }
    cout << fixed;
    cout.precision(1);
    cout << 0.5*abs(acc);
}