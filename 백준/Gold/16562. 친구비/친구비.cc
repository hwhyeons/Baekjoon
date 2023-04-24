#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;


vector<int> parents;
vector<ll> prices;
int get_parent(int idx) { // 최적화 유니온 파인드
    if (parents.at(idx) == idx) return idx;
    else {
        parents.at(idx) = get_parent(parents.at(idx));
        return parents.at(idx);
    }
}

void merge(int idx1, int idx2) {
    int p1 = get_parent(idx1);
    int p2 = get_parent(idx2);
    if (p1 == p2) return; // 이미 그룹화 되어 있는 경우
    else {
        if (p1 > p2) {
            parents.at(p1) = parents.at(p2);
        } else {
            parents.at(p2) = parents.at(p1);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    parents.assign(n+1,0);
    prices.assign(n+1,0);
    for (int i = 1; i <= n; ++i) {
        ll tmp; cin>>tmp;
        prices[i] = tmp;
    }
    iota(parents.begin(), parents.end(),0);
    for (int i = 0; i < m; ++i) {
        int t1,t2;
        cin >> t1 >> t2;
        merge(t1,t2);
    }

    ll acc = 0l;
//    vector<bool> vst(n+1,false);
    unordered_map<int,ll> group_price_min; // 그룹 변호별 최소 비용
    for (int i = 1; i <= n; ++i) {
        int group_num = get_parent(i);
        ll cur_price = prices.at(i);
        if (group_price_min.contains(group_num)) {
            group_price_min[group_num] = min(group_price_min[group_num],cur_price);
        } else {
            group_price_min[group_num] = cur_price;
        }
    }

    for (auto &pair: group_price_min) {
        acc += pair.second;
    }

    if (acc > k) {
        cout << "Oh no";
    } else{ cout << acc;}

}