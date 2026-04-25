#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
typedef long double ld;
using namespace std;

// 예를들어 12 = 2^2*3이라면 원소 개수는 중요하지 않고 2와 3이 포함된 벡터 리턴
vector<ll> getAllPrimeFactors(ll n) {
    vector<ll> factors;
    ll temp = n;

    for (ll i = 2; i * i <= temp; ++i) {
        if (temp % i == 0) {
            factors.push_back(i);
            // 해당 소인수로 나누어 떨어지지 않을 때까지 나눔 (중복제거)
            while (temp % i == 0) {
                temp /= i;
            }
        }
    }
    // 남은 수가 1보다 크면 추가
    if (temp > 1) {
        factors.push_back(temp);
    }
    return factors;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (1) {
        int n;
        cin >> n;
        if (n==0) break;

        // 일반적인 오일러 피 함수와 다르게 이 문제는 조건에 따라 1일 때 답이 0이 나옴
        if (n==1) {
            cout << "0\n";
            continue;
        }

        vector<ll> primes = getAllPrimeFactors(n);
        // 배수를 전부 제거하는 작업 (곱 비율 제거)
        // 예를들어 n=12에서 소인수는 2와 3이므로
        // 12*(1-1/2)*(1-1/3)
        ll cur = n;
        for (ll prime : primes) {
            cur = cur/prime*(prime-1ll);
        }
        cout << cur << "\n";
    }
}