#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

// -1,0,1
int ccw(int x1, int y1, int x2, int y2,int x3, int y3) {
    int k = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (k >0) return 1;
    if (k ==0) return 0;
    if (k < 0) return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t1,t2;
    cin >> t1 >> t2;
    auto p1 = make_pair(t1,t2); // x,y순서!
    cin >> t1 >> t2;
    auto p2 = make_pair(t1,t2);
    cin >> t1 >> t2;
    auto p3 = make_pair(t1,t2);
    cin >> t1 >> t2;
    auto p4 = make_pair(t1,t2);


    int a = ccw(p1.first,p1.second,p2.first,p2.second,p3.first,p3.second);
    int b = ccw(p1.first,p1.second,p2.first,p2.second,p4.first,p4.second);
    int c = ccw(p3.first,p3.second,p4.first,p4.second,p1.first,p1.second);
    int d = ccw(p3.first,p3.second,p4.first,p4.second,p2.first,p2.second);
    vector<int> all{a,b,c,d};

    int ab = a*b;
    int cd = c*d;
    // 하나라도 양수면 X
    if (a*b > 0 || c*d > 0) {
        cout << 0;
    } else if (a*b==-1 && c*d == -1) { // 제대로 교차
        cout << 1;
    } else if (ab == 0 || cd == 0) {
        cout << 0;
//        if ((ab == 0 && cd < 0) || (cd == 0 && ab < 0)) {
//            cout << 1;
//        } else {
//            cout << 0;
//        }
    } else {
        cout << 1;
    }
}