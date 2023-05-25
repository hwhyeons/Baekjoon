#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            string t; cin >> t;
            v.push_back(t.size());
        }
        int before = 0;
        int startIdx = 0;
        int idx = 0;
        int cnt[] = {5,7,5,7,7};
        for (int i = 0; i < v.size(); ++i) {
            if (before+v[i] == cnt[idx]) {
                before = 0;
                if (idx == 4) {
                    break;
                } else idx++;
            } else if (before+v[i] > cnt[idx]) {
                idx = 0;
                before = 0;
                startIdx += 1;
                i = startIdx-1;
            } else {
                before += v[i];
                continue;
            }
        }
        cout << startIdx+1 << "\n";
    }


}