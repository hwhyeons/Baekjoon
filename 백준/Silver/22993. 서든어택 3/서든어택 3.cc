// #pragma optimize("", off)
#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<ll> v;
    for (size_t i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
    sort(v.begin() + 1, v.end()); // 준원 제외하고 정렬
    ll cur = v.at(0);
    for (size_t i = 1; i < N; i++) {
        ll other = v.at(i);
        if (cur > other) {
            cur += other;
        } else {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}