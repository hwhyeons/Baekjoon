#include <algorithm>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <limits.h>
#include <iostream>
#include <string>

using namespace std;
#define ll long long

class cd {
public:
    int idx,val;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,tmp;
    cin >> n;
    stack<cd> s;
    vector<int> ans(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        cd c;
        c.idx = i+1;
        c.val = tmp;
        if (!s.empty()) {
            int top_val = s.top().val;
            if (top_val >= c.val) { // 벽에 부딪히는 경우
                ans[c.idx] = s.top().idx;
            } else {
                s.pop();
                while(!s.empty()) {
                    if (s.top().val > c.val) {
                        ans[c.idx] = s.top().idx;
                        break;
                    }
                    s.pop();
                }
            }
            s.push(c);
        } else {
            s.push(c);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    // 정답이 아닌 경우 : ans vector가 0으로 초기화 되어 있으므로 따로 작업 필요 X



}
