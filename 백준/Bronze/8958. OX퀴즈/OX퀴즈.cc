#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
using namespace std;

int main() {
    ranges::for_each(ranges::istream_view<string>(cin) | views::drop(1),[](auto s) {
        regex r("X+");
        auto it = sregex_token_iterator(s.begin(), s.end(), r, -1);
        auto end = sregex_token_iterator();
        ll acc = 0ll;
        while (it != end) {
            int len = (*it).length();
            acc += ((len) * (len + 1)) / 2;
            it++;
        }
        *ostream_iterator<int>(cout, "\n")++ = acc;
    });
}