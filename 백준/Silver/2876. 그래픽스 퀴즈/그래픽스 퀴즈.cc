#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt;
    cin >> cnt;
    vector<vector<int>> v(cnt,vector<int>(2));
    for (int i = 0; i < cnt; ++i) {
        cin >> v[i][0] >> v[i][1];
    }
    int ansGrade = -1;
    int ansCnt = -1;
    for (int grade = 1; grade <= 5; ++grade) {
        // 투포인터
        int s=0,e=0;
        int max_len = -1;
        int len = 0;
        while (s < cnt && e < cnt) {
            len = e-s+1;
            if (v[e][0] == grade || v[e][1] == grade) {
                max_len = max(len, max_len);
                e++;
            } else {
                e++;
                s = e;
            }
        }
        if (max_len > ansCnt) {
            ansCnt = max_len;
            ansGrade = grade;
        }
    }
    cout << ansCnt << " " << ansGrade;
}