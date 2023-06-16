#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < n; ++i) {
        int t1,t2;
        cin >> t1 >> t2;
        pq.push({-t1,t2});
    }
    int curTime = 0;
    while (!pq.empty()) {
        auto [start,pro] = pq.top();
//        pq.pop();
        start *= -1;
        if (start > curTime) {
            curTime = start;
            continue;
        }
        else pq.pop();
        curTime += pro;
    }
    cout << curTime;
}