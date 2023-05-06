#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

ll ans = LLONG_MAX;

ll b;
void dfs(ll num, ll cnt) {
    if (num == b) {
        ans = min(ans,cnt);
        return;
    }
    if (num > b) return;
    dfs(num*10+1,cnt+1);
    dfs(num*2,cnt+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a;
    cin >> a >> b;
    dfs(a*10+1,1);
    dfs(a*2,1);

    if (ans == LLONG_MAX) {
        cout << -1;
    } else {
        cout << ans+1;
    }

}