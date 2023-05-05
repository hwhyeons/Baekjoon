#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

char convert(int num) {
    if (num < 10) {
        return num+'0';
    } else {
        return num-10+'A';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    int dig;
    cin >> num >> dig;
    int cur = num;
    stack<char> stk;
    while (true) {
        int q = cur/dig; // 몫
        int r = cur%dig; // 나머지
        if (q < dig) {
            char rc = convert(r);
            char qc = convert(q);
            stk.push(rc);
            stk.push(qc);
            break;
        } else {
            char rc = convert(r);
            stk.push(rc);
            cur = q;
        }
    }

    if (stk.top() == '0') {
        stk.pop();
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }


}