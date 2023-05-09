#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tcnt;
    cin >> tcnt;
    int tc=1;
    while (tcnt--) {
        int areaCnt; cin >> areaCnt;
        vector<pair<ll,ll>> v;
        for (int i = 0; i < areaCnt; ++i) {
            ll t1,t2,t3,t4;
            cin >> t1 >> t2 >> t3 >> t4;
            for (int j = t1; j <= t3; ++j) {
                for (int k = t2; k <= t4; ++k) {
                    v.emplace_back(j,k);
                }
            }
        }
        vector<tuple<ll,ll,ll>> allDist;
        // 모든 좌표에서 거리 계산
        for (int i = 0; i < v.size(); ++i) {
            ll acc =0;
            auto [x1,y1] = v.at(i);
            for (int j = 0; j < v.size(); ++j) {
                if (i == j) continue;
                auto [x2,y2] = v.at(j);
                acc += abs(x2-x1) + abs(y2-y1);
            }
            allDist.emplace_back(acc,x1,y1);
        }
        std::sort(allDist.begin(), allDist.end());
        auto [ans,ansX,ansY] = allDist.front();
        cout << "Case #" << tc++ << ": " << ansX << " " << ansY << " " << ans << "\n";
    }
}