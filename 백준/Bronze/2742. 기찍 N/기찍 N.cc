#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    std::iota(v.begin(), v.end(),1);
    std::for_each(v.rbegin(), v.rend(),[](int i){
        cout << i << "\n";
    });
}