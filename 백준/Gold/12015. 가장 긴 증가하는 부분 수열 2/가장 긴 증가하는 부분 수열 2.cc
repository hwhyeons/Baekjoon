#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    vector<int> ans = { 100000000 };
    for (auto& cur : v) {
        if (cur > ans.back()) {
            ans.push_back(cur);
            continue;
        }
        auto upperIter = lower_bound(ans.begin(), ans.end(), cur);
        int changeIdx = upperIter - ans.begin();
        ans[changeIdx] = cur;
    }
    cout << ans.size();


}