#include <bits/stdc++.h>
#include <ranges>

typedef long long ll ;

using namespace std;

double get_len(int radius) {
    return 2*radius*3.1415926535897932384626;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double all;
    cin >> all;
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; ++i) {
        int t1,t2;
        cin >> t1 >> t2;
        v.emplace_back(t2,t1);
    }
    ranges::sort(v);
    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        auto p = v[i];
        double price = get_len(p.first);
        int can_count = (int)(all / price);
        if (can_count == p.second) {
            ans+=can_count;
            break;
        } else if (can_count > p.second) {
            ans+=p.second;
            all -= p.second*price;
            continue;
        } else {
            ans+=can_count;
            break;
        }
    }
    cout << ans;

}