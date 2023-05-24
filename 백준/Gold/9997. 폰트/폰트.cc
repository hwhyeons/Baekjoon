#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

vector<bitset<26>*> all;

int answer = 0;
void dfs(int idx, bitset<26>& out) {
    auto* bs = all.at(idx);
    auto newBitSet = (*bs) | out;
    if (newBitSet.all()) {
        answer++;
    }
    for (int i = idx+1; i < all.size(); ++i) {
        dfs(i,newBitSet);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string tmp; cin >> tmp;
        auto* bs = new bitset<26>();
        for (char c : tmp) {
            int bitIndex = c - 'a';
            bs->set(bitIndex, true);
        }
        all.push_back(bs);
    }
    bitset<26> out;
    for (int i = 0; i < all.size(); ++i) {
        dfs(i,out);
    }
    cout << answer;



}