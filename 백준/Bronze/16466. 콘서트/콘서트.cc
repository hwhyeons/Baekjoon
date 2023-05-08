#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
using namespace std;

int main() {
    vector<int> v;
    auto vi = ranges::istream_view<int>(cin) | views::drop(1);
    for (auto k : vi) v.emplace_back(k);
    ranges::sort(v);
    auto it = ranges::adjacent_find(v,[](int& a,int &b){
        return b != a+1;
    });
    cout << (v.front() !=1 ? 1 : (it == v.end() ? *(--it)+1: *it+1));
}