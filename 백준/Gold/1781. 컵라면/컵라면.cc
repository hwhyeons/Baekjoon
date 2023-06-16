#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>> v(200001);
    priority_queue<pair<ll,ll>> pq;
    for (int i = 0; i < n; ++i) {
        ll t1,t2; cin >> t1 >> t2;
        v[t1].push_back(t2);
    }

    int curTime = 200001;
    vector<ll> vAns(200001);
    while (curTime >= 1) {
        // 시간 데드라인 충족하는 것들 다 넣기
        if (!v[curTime].empty()) {
            for (ll val: v[curTime]) {
                pq.push({val,-curTime});
            }
        }
        lb:
        if (!pq.empty()) {
            auto [cup,dead] = pq.top();
            pq.pop();
            dead = dead*-1;
            if (curTime > dead) { // 여기 equal주의
                pq.pop();
                goto lb;
            }
            vAns[curTime] = cup;
        }
        curTime--;
    }
    cout << accumulate(vAns.begin(), vAns.end(),0ll);
}