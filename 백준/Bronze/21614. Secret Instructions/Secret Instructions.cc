#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;


string before = ""; // true -> left
int main() {
    ranges::copy(ranges::istream_view<string>(cin) | views::take_while([](string& s){return s != "99999";})
                 | views::transform([](auto& s){
        auto sub = s.substr(0,2);
        before = sub == "00"? before : ((sub[0]+sub[1]+2*'0')%2 ? "left" : "right");
        return before+" "+s.substr(2,3);
    }),ostream_iterator<string>(cout,"\n"));
    return 0;
}