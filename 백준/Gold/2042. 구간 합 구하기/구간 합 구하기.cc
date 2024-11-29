#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
typedef long long ll;
using namespace std;

// -----------------------------------------
// -----------------------------------------
// -----------------------------------------

vector<ll> v;
vector<ll> seg;

ll calculate(ll left, ll right) {
    return left + right;
}

ll initTree(int node, int s, int e) {
    if (s == e) {
        seg[node] = v[s];
        return seg[node];
    }

    ll left = initTree(node * 2, s, (s + e) / 2);
    ll right = initTree(node * 2 + 1, (s + e) / 2 + 1, e);
    ll acc = calculate(left, right);
    seg[node] = acc;
    return seg[node];
}

ll update(int node, int s, int e, int changeIndex, ll changeValue) {
    if (changeIndex < s || changeIndex > e) return seg[node];
    if (s == e) {
        v[changeIndex] = changeValue;
        seg[node] = changeValue;
        return changeValue;
    }

    ll left = update(node * 2, s, (s + e) / 2, changeIndex, changeValue);
    ll right = update(node * 2 + 1, (s + e) / 2 + 1, e , changeIndex, changeValue);
    ll result = calculate(left, right);
    seg[node] = result;
    return result;
}

ll query(int node, int s, int e, int l, int r) {
    if (l <= s && r >= e) return seg[node];
    if (r < s || l > e) return 0;

    ll left = query(node * 2, s, (s + e) / 2, l, r);
    ll right = query(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
    ll result = calculate(left, right);
    return result;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    for (size_t i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    seg.assign(4*N, 0);
    initTree(1, 0, v.size() - 1);

    for (size_t i = 0; i < M+K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            // 이 문제에서는 b가 1부터 시작하므로 0번인덱스로 조정
            update(1, 0, v.size() - 1, b - 1, c);
        } else if (a == 2) {
            cout << query(1, 0, v.size() - 1, b - 1, c - 1) << "\n";
        }
    }

}