#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <bitset>
typedef long long ll;
using namespace std;

// -----------------------------------------
// -----------------------------------------
// -----------------------------------------

class Attack {
public:
    int second;
    int target;
};

void solve(int startNumber, vector<vector<Attack>>& attack, int n) {
    int curTime = 0;
    int ans = 0; // 감염자 수 
    vector<bool> visit(n + 1, false);
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // 시간, 타겟넘버
    vector<Attack>& starter = attack[startNumber];
    for (Attack& a : starter) {
        pq.push({ curTime + a.second,a.target });
    }
    visit[startNumber] = true;
    ans++;
    while (!pq.empty()) {
        auto [time, targetNumber] = pq.top(); pq.pop();
        if (visit[targetNumber]) continue;
        visit[targetNumber] = true;
        ans++;
        curTime = max(curTime,time);
        vector<Attack>& nextTargetList = attack[targetNumber];
        for (Attack& a : nextTargetList) {
            pq.push({ curTime + a.second,a.target });
        }
    }

    cout << ans << " " << curTime << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (size_t i = 0; i < T; i++) {
        int n, d, c;
        cin >> n >> d >> c;
        vector<vector<Attack>> attack(n + 1); // 의존성
        for (size_t j = 0; j < d; j++) {
            int a, b, s;
            cin >> a >> b >> s;
            attack[b].push_back({ s,a});
        }

        solve(c, attack,n);

    }
}