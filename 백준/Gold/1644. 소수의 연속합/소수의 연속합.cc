#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<bool> er_visit(N + 1); // 에라토스테네스의 체
    er_visit[0] = true;
    er_visit[1] = true;
    vector<int> v_primes(1);
    for (int i = 2; i <= N; ++i) {
        if (!er_visit.at(i)) {
            v_primes.push_back(i);
            er_visit.at(i) = true;
            for (int multiple_const = 2; multiple_const * i <= N; multiple_const++) {
                er_visit[multiple_const*i] = true;
            }
        }
    }
    vector<int> acc(v_primes.size());
    // 소수 누적합 계산
    for (int i = 1; i < acc.size(); ++i) {
        acc[i] = acc.at(i-1)+v_primes.at(i);
    }
//    vector<ll> all_part_sum; // 모든 "부분합"

    ll answer = 0;

    int left = 1, right = 1;
    while (left <= right && right < acc.size()) {
        ll part_sum = acc[right]-acc[left-1];
        if (part_sum == N) answer++;
        if (part_sum >= N) {
            left++;
        } else {
            right++;
        }
    }
    cout << answer;
}