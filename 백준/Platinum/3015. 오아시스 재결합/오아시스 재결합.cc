#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const long long NO_LEFT = 3000000000LL;

long long N;
vector<long long> v;
long long ans = 0;
long long cur_idx = 0;

void dfs(long long left_value) {
    vector<pair<long long,long long>> stk;  // (value, count)
    while (true) {
        // 종료 조건: 배열 끝에 도달했거나, left_value보다 크거나 같은 값을 만났을 때
        if (cur_idx >= N || (left_value != NO_LEFT && v[cur_idx] >= left_value)) {
            long long acc = 0;
            // 인접 원소 계산
            acc += static_cast<long long>(stk.size()) - 1;
            for (size_t ti = 0; ti < stk.size(); ++ti) {
                long long cnt = stk[ti].second;
                if (cnt >= 2) {
                    // 중복 요소 내부 연산: nC2 = (n-1)*n/2
                    acc += (cnt - 1) * cnt / 2;
                }
                if (ti >= 1 && stk[ti-1].second >= 2) {
                    acc += stk[ti-1].second - 1;
                }
            }
            // left_value와의 연산
            if (left_value != NO_LEFT) {
                for (auto &tp : stk) {
                    acc += tp.second;
                }
            }
            // right_value와의 연산
            if (cur_idx <= N - 1 && !stk.empty()) {
                acc += stk.back().second;
            }
            ans += acc;
            return;
        }

        // 오름차순이 깨지면 재귀 호출
        if (!stk.empty() && v[cur_idx] < stk.back().first) {
            dfs(v[cur_idx - 1]);
            continue;
        }

        // 중복 값 처리: 개수 누적
        if (!stk.empty() && stk.back().first == v[cur_idx]) {
            auto last = stk.back();
            stk.pop_back();
            last.second++;
            stk.push_back(last);
        } else {
            stk.emplace_back(v[cur_idx], 1);
        }

        ++cur_idx;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    v.resize(N);
    for (long long i = 0; i < N; ++i) {
        cin >> v[i];
    }

    dfs(NO_LEFT);
    cout << ans << "\n";
    return 0;
}