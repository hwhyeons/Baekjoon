#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> vst(1000001);
    vector<int> primes;
    unordered_set<int> primesSet;
    // 모든 소수 계산
    for (int i = 2; i <= 1000000; ++i) {
        if (vst.at(i)) continue;
        vst.at(i) = true;
        if (i%2 == 1) {
            primes.push_back(i); // 홀수인 경우에서만 추가
            primesSet.insert(i);
        }
        for (int j = 2; i*j <= 1000000; ++j) {
            vst.at(i*j) = true;
        }
    }

    while (true) {
        int num;
        cin >> num;
        if (num == 0) break;
        bool ok = false;
        for (int i = 0; i < primes.size(); ++i) {
            int a = primes.at(i);
            int b = num - a;
            if (a > b) break;
            if (primesSet.contains(b)) {
                cout << num << " = " << a << " + " << b << "\n";
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}