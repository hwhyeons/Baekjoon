#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,s2;
    getline(cin, s);
    getline(cin, s2);
    regex r(" ");
    int m = stoi(s2);
    vector<string> v(sregex_token_iterator(s.begin(), s.end(),r,-1), sregex_token_iterator());
    auto a = v | views::transform([](string& str){ return stoi(str); });
    vector<int> all(a.begin(),a.end());
    set<pair<int,int>> st;
    for (int i = 0; i < all.size(); ++i) {
        for (int j = i+1; j < all.size(); ++j) {
            int &k1 = all.at(i);
            int &k2 = all.at(j);
            if (k1 + k2 == m) {
                if (k1 > k2) swap(k1,k2);
                st.emplace(k1, k2);
            }
        }
    }
    ranges::for_each(st,[](auto pair){cout << pair.first <<" "<<pair.second << " \n";});
    cout << st.size();
}