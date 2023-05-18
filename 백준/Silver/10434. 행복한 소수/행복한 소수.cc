#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_set<int> pr;
    vector<bool> vst(10001);
    for (int i = 2; i <= 10000; ++i) {
        if (vst[i]) continue;
        else {
            pr.insert(i);
            for (int j = 1; i*j <= 10000; ++j) {
                vst[i*j] = true;
            }
        }
    }
    int tcnt;
    cin >> tcnt;
    while (tcnt--) {
        int tnum; cin >> tnum;
        int num; cin >> num;
        bool ans = false;
        if (pr.contains(num)) {
            unordered_set<ll> beforeMeet;
            // 제곱 처리
            string s = to_string(num);
            lb:
            auto view = s | views::transform([](char c){return ((ll)c-'0')*((ll)c-'0');});
            ll acc = accumulate(view.begin(), view.end(),0ll);
            if (acc == 1) {
                ans = true;
                goto ansLb;
            } else {
                if (beforeMeet.contains(acc)) {
                    goto ansLb;
                } else {
                    beforeMeet.insert(acc);
                    s = to_string(acc);
                    goto lb;
                }
            }
        }
        ansLb:
        cout << tnum << " " << num << (ans ? " YES\n" : " NO\n");
    }

}