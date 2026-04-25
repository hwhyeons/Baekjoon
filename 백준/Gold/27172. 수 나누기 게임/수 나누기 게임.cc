#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ranges>
// #include<bits/stdc++.h>
#include <limits>
typedef long long ll;
typedef long double ld;
using namespace std;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N);
    unordered_map<int,int> m;
    for (int i=0; i<N;i++) {
        cin >> v[i];
        m[v[i]] = 0;
    }

    for (int num : v) {
        for (int cst=2; cst*num<=1000000ll; cst++) {
            int multiple = cst*num;
            if (m.find(multiple) != m.end()) {
                m[multiple] -= 1;
                m[num] += 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << m[v[i]] << " ";
    }



}