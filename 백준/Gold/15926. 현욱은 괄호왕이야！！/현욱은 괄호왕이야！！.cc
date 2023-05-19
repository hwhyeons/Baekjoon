#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
//    stack<int> st; // -1이 들어가면 (
    int depth = 0;
    vector<int> v(200001,0); // 깊이별 값
    int mx = 0;
    while (n--) {
        char c; cin >> c;
        if (c == '(') {
            depth++;
        } else if (c == ')') {
            if (depth > 0) {
                v[depth-1] += v[depth]+2;
                v[depth] = 0;
                depth--;
            } else {
                mx = max(mx,v.front());
                v.front() = 0;
            }
        }
    }
    cout << max(*max_element(v.begin(), v.end()),mx);
}