#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,a,d,tmp;
    cin >> n >> a>>d;
    int want = a;
    int ans = 0;
    while (n--) {
        cin >> tmp;
        if (tmp == want) {
            ans++;
            want+=d;
        }
    }
    cout << ans;
}