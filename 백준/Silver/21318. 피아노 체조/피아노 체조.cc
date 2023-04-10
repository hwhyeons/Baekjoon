#include <bits/stdc++.h>
#include <ranges>

typedef long long ll ;

using namespace std;

ll divide = 1000000009ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    // 누적 실수 횟수
    vector<int> v(n + 2); // 맨 앞과 맨 뒤를 비워둠
    ll before;
    cin >> before;
    for (int i = 2; i <= n; ++i) {
        ll t; cin >> t;
        if (t < before) {
            v[i-1] = v[i-2]+1;
        } else {
            v[i-1] = v[i-2];
        }
        before = t;
    }
    v[n] = v[n-1];

    int tcnt; cin >> tcnt;
    while (tcnt--) {
        ll t1,t2;
        cin >> t1 >> t2;
        if (t1 == t2) {
            cout << 0 << "\n";
            continue;
        }
        cout << v[t2-1]-v[t1-1] << "\n";
    }


}