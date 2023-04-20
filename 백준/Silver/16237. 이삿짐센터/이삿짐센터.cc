#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;
vector<int> v(6);
vector<int> basket;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v[1] >> v[2] >> v[3] >> v[4]  >> v[5];
    for (int i = 5; i >= 1; --i) {
        int& cur_cnt = v[i];
        while (true) {
            if (cur_cnt == 0) break;
            if (basket.empty()) {
                basket.push_back(0);
                continue;
            }
            bool ok = false;
            for (int j = 0; j < basket.size(); ++j) {
                if (basket[j]+i <= 5){
                    basket[j]+=i;
                    cur_cnt--;
                    ok = true;
                    break;
                }
            }
            // 하나도 못넣은 경우
            if (!ok) basket.push_back(0);
        }
    }
    cout << basket.size();


}