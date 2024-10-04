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
    int N;
    cin >> N;
    vector<int> v(N);
    for (size_t i = 0; i < v.size(); i++) cin >> v[i];
    vector<int> dp(v.begin(), v.end()); // 깊은복사배열 복사

    for (int idx = 0; idx < dp.size(); idx++) {
        int curVal = v.at(idx);
        for (int r = idx - 1; r >= 0; r--) {
            if (v[r] < curVal) { // 작은 값 : 누적시키기
                dp[idx] = max(dp[idx], v[idx]+dp[r]);
            }
        }
    }
    cout << *ranges::max_element(dp);
}