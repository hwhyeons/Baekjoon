#include <bits/stdc++.h>
#include <ranges>

typedef long long ll ;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int all_count = 'z'-'a'+1;
    int tcnt; cin >> tcnt;
    while (tcnt--) {
        string s;
        cin >> s;
        int want;
        cin >> want;


        // 어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열
        vector<int> v(all_count, 0);
        int mn = INT_MAX;
        int si =0,ei=0;
        bool is_before_end_pp = true;
        char c;
        int c_idx;
        while (si <= ei && ei < s.size()) {
            if (is_before_end_pp) { // 방금 뒤쪽 증가
                c = s[ei];
                c_idx = c-'a';
                v[c_idx]++;
            }
            if (v[c_idx] >= want) {
                mn = min(mn,ei-si+1);
                v[s[si]-'a']--;
                si++;
                is_before_end_pp = false;
            } else {
                ei++;
                is_before_end_pp = true;
            }
        }


        if (mn == INT_MAX) {
            cout << -1 << "\n";
            continue;
        }


        // 어떤 문자를 정확히 K개를 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열
        int mx = -1;
        if (want == 1) {
            mx = 1;
        } else {
            vector<deque<int>> vd(all_count);
            for (int i = 0; i < s.size(); ++i) {
                char c = s[i];
                int idx = c-'a';
                vd[idx].push_back(i);
                if (vd[idx].size() == want) {
                    mx = max(mx,vd[idx].back()-vd[idx].front()+1);
                    vd[idx].pop_front();
                }
            }
            if (mx == -1 ){
                cout << -1 << "\n";
                continue;
            }
        }
        // answer ok
        cout << mn << " " << mx << "\n";
    }
}