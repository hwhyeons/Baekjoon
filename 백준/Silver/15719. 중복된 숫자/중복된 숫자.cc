#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

bitset<10000000> bs;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ranges::for_each(ranges::istream_view<int>(cin),[](int n){
        if (!(bs[n]=~bs[n])) cout << n;
    });
    return 0;
}