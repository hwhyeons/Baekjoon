#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

// -1,0,1
int ccw(int x1, int y1, int x2, int y2,int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t1,t2;
    cin >> t1 >> t2;
    auto p1 = make_pair(t1,t2); // x,y순서!
    cin >> t1 >> t2;
    auto p2 = make_pair(t1,t2); // x,y순서!
    cin >> t1 >> t2;
    auto p3 = make_pair(t1,t2); // x,y순서!
    int answer = ccw(p1.first,p1.second,p2.first,p2.second,p3.first,p3.second);
    cout << (answer < 0 ? -1 : (answer == 0 ? 0 : 1));

}