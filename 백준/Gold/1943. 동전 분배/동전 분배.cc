#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int t = 0; t < 3; t++) {
        cin >> n;
        // 동전 가격,  갯수
        vector<pair<int, int>> value;
        int obj = 0;
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            value.push_back({ a, b });
            obj += (a * b);
        }
        // 반반 불가
        if (obj % 2 != 0) {
            cout << 0 << "\n";
            continue;
        }

        // 가능 금액
        vector<bool> dp(obj+1, false);
        dp[0] = true;


        obj = obj / 2;

        // dp로 반 나누기 가능한지 검증
        for (auto [price, cnt] : value) {
            for (int p = 1; cnt > 0; p <<= 1) {
                int take = min(p, cnt);           // 1,2,4,8,… 씩 잘라서
                int money = take * price;
                for (int k = obj; k >= money; --k)
                    if (dp[k - money]) dp[k] = true;
                cnt -= take;
            }
        }
        if (dp[obj]) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }

    return 0;
}