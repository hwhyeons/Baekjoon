#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K;
    cin >> N >> K;
    vector<int> v(N+1);
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        v[t]++;
    }

    vector<int> left;
    deque<int> no;
    // 없는 숫자 찾기 및 남는 숫자
    for (int i = 1; i <= N; ++i) {
        if (v[i] == 0) {
            no.push_back(i);
        } else if (v[i] >= 2) {
            // 예를 들어 4라는 숫자가 3개 있으면 남는 벡터에 4를 2번 추가
            for (int j = 0; j < v[i]-1; ++j) {
                left.push_back(i);
            }
        }
    }

    // 바로 통과
    if (no.empty()) {
        cout << 1;
        return 0;
    }
    while (!no.empty()) {
        int no_cur = no.front(); no.pop_front();
        bool go_next = false;
        for (int i = 0; i < left.size(); ++i) {
            int cur_left = left[i]; // 활용할 숫자

            // 남는 숫자가 4인데 없는 숫자가 2인 경우
            if (cur_left > no_cur) {
                cout << 0;
                return 0;
            }
            // 가능한 경우 (나누어 떨어짐)
            else if ((no_cur-cur_left)%K == 0) {
                left.erase(left.begin()+i); // 현재꺼 제거
                go_next = true;
                break;
            } else { // 다음 숫자로
                continue;
            }
        }

        // 만약에 left 벡터 for문 다 돌았는데 없으면 못만드는 것
        if (go_next) {
            continue;
        } else {
            cout << 0;
            return 0;
        }
    }
    cout << 1;



}