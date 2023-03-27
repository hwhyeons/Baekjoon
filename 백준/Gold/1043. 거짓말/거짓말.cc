#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ranges>
#include <map>

#define ll long long

using namespace std;

class node {
public:
    unordered_set<int> f;
    bool visit;
};

vector<node> all;
unordered_set<int> bad; // 최종적으로 거짓말 못하는 사람
void dfs(int idx) {
    unordered_set<int>& f = all[idx].f;
    all[idx].visit = true;
    bad.insert(idx);
    for (int fr : f) {
        if (all[fr].visit) continue;
        bad.insert(fr);
        dfs(fr);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,know;
    cin >> n >> m;
    cin >> know;
    if (know == n) {
        cout << 0;
        return 0;
    }
    all.emplace_back(); // 임시 노드 추가
    for (int i = 1; i <= n; ++i) {
        all.emplace_back();
    }
    unordered_set<int> start;
    vector<unordered_set<int>> party(m+1);

    for (int i = 1; i <= know; ++i) {
        int t;
        cin >> t;
        start.insert(t);
    }

    if (start.empty()) {
        cout << m;
        return 0;
    }


    for (int i = 1; i <= m; ++i) {
        int tmp; cin >> tmp;
//        vector<int> num;
        // tmp : 현재 파티 인원
        for (int j = 1; j <= tmp; ++j) {
            int t3; cin >> t3;
//            num.push_back(t3);
            party[i].insert(t3);
        }

        for (int k: party[i]) {
            for (int k2: party[i]) {
                all[k].f.insert(k2);
            }
        }
    }


    for (int idx: start) {
        if (!all[idx].visit) {
            dfs(idx);
        }
    }

    int ans =0;
    for (int i = 1; i < party.size(); ++i) {
        unordered_set<int>& s = party[i];
        bool ok = true;
        for (int idx : s) {
            if (bad.contains(idx)) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans;

}




