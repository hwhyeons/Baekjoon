#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int n;

/**
 * @param cur 현재 몇번째 감소하는 수인지
 * @param digit 현재 자릿수
 * @param digit_num 자릿수의 숫자
 */
void dfs(long long& cur,int digit, int digit_num,vector<int>& out) {
    out[11-digit] = digit_num;

    if (digit == 1) {
//        cout << "cur : " << cur << "  /  ";
//        for (int i =0; i<11; ++i) {
//            cout << out[i];
//        }
//        cout << "\n";
        if (cur == n) {
            bool flag = true;
            for (int i =0; i<11; ++i) {
                if (out[i] == 0 && flag) {
                    continue;
                }
                flag = false;
                cout << out[i];
            }
            exit(0);
        }
        cur++;
        return;
    }
    for (int i = 0; i<=digit_num-1; i++) {
        dfs(cur,digit-1,i,out);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n <= 9) {
        cout << n; return 0;
    }
    vector<int> out(11);
    long long start = 10;
    for (int i = 2; i < 11; ++i) {
        for (int j = 1; j <= 9; ++j) { // 첫번째 자리수는 1이상
            dfs(start,i,j,out);
        }
    }
    cout << -1;
}