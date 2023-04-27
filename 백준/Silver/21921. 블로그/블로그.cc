#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // 맨 처음 합은 미리 계산
    ll mx = accumulate(v.begin(),v.begin()+x,0ll);
    int s= 1,e=x; // 1번 인덱스부터 출발
    ll before_sum = mx;
    int max_cnt = 1;
    while (e < v.size()) {
        ll cur = before_sum - v.at(s-1) + v.at(e);
        if (cur == mx) {
            max_cnt++;
        } else if (cur > mx) { // 최대 갱신
            mx = cur;
            max_cnt = 1;
        }
        before_sum = cur;
        s++;
        e++;
    }

    if (mx == 0) {
        cout << "SAD";
        return 0;
    } else {
        // 종류 체크
        cout << mx << "\n";
        cout << max_cnt;
    }

    return 0;
}