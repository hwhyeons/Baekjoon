#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    deque<int> minus;
    deque<int> zero;
    deque<int> plus;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        if (t < 0) {
            minus.push_back(t);
        } else if (t == 0) {
            zero.push_back(t);
        } else {
            plus.push_back(t);
        }
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end(),greater<>());


    int answer = 0;

    // 음수 처리
    while (!minus.empty()) {
        int a = minus.front(); minus.pop_front();
        if (minus.empty()) {
            if (!zero.empty()) { // a랑 0이랑 엮어 버리기
                zero.pop_front();
            } else {
                answer += a;
                break;
            }
        } else {
            int b = minus.front(); minus.pop_front();
            answer += a*b;
        }
    }

    // 남은 0은 처리 필요 X

    while (!plus.empty()) {
        int a = plus.front(); plus.pop_front();
        // 1이면 계속 더해주면 됨
        if (a == 1) {
            answer+=1;
            continue;
        }
        // 남은게 a밖에 없으면 더하고 종료
        if (plus.empty()) {
            answer+=a;
            break;
        }

        // a는 1보다 큰데 b는 1인 경우 : a랑 b를 각자 더하기
        int b = plus.front(); plus.pop_front();
        if (b == 1) {
            answer = answer + a + b;
            continue;
        } else {
            answer += a*b;
        }
    }

    cout << answer;


}
