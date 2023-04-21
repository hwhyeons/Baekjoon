#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

void get_all_part_sum(unordered_map<ll,int>& mp, vector<ll>& v_acc) {

    // cnt : 부분합 몇개
    for (int cnt = 1; cnt <= v_acc.size(); ++cnt) {
        for (int i = 1; i <= v_acc.size()-cnt; ++i) {
            ll part_sum = v_acc.at(i+cnt-1) - v_acc.at(i-1);
            if (mp.contains(part_sum)) {
                mp[part_sum]+=1;
            } else {
                mp[part_sum]=1;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    int n;
    cin >> n;
    vector<ll> acc1(n+1); // 누적합
    for (int i = 1; i <= n; ++i) {
        ll tmp;
        cin >> tmp;
        acc1[i] = acc1[i-1] + tmp;
    }
    int m;
    cin >> m;
    vector<ll> acc2(m+1);
    for (int i = 1; i <= m; ++i) {
        ll tmp;
        cin >> tmp;
        acc2[i] = acc2[i-1] + tmp;
    }

    // 모든 부분합 전부 계산해서 맵에 추가
    unordered_map<ll,int> m1; // (부분합 / 갯수)
    unordered_map<ll,int> m2; // (부분합 / 갯수)


    ll answer = 0;
    get_all_part_sum(m1,acc1);
    get_all_part_sum(m2,acc2);
    for (auto p : m1) {
        ll a = p.first;
        ll a_cnt = p.second;
//        if (a >= T) continue; // T가 10인데 뽑은 부분합이 20인 경우 >> 음수가 나올 수 있으므로 가능함
        ll gap = T - a;
        ll b_cnt = m2.contains(gap) ? m2[gap] : 0;
        answer += a_cnt*b_cnt;
//        if (a_cnt*b_cnt > 0) cout << "ok : " << a << " " << gap << endl;
    }

    cout << answer;


}