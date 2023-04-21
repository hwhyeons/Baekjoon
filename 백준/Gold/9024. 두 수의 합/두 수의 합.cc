#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcnt;
    cin >> tcnt;
    while (tcnt--) {
        int n,k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        int s=0,e=v.size()-1;
        ll mn = LLONG_MAX;
        int answer = 0;
        while (s < e) {
            ll gap  = (v[s]+v[e])-k;
            if (abs(gap) < abs(mn)) {
                answer=1;
                mn = gap;
            } else if (abs(gap) == abs(mn)) {
                answer++;
            }
            if (gap < 0) {
                s++;
            } else if (gap >= 0){
                e--;
            }
        }
        cout << answer << "\n";
    }

}