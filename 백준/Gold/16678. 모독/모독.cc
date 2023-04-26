#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_set<int> all_tmp;
    deque<int> lefts;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (all_tmp.contains(t)) {
            lefts.push_back(t);
        } else {
            all_tmp.insert(t);
        }
    }
    // all에는 중복이 있으면 안됨
    deque<int> all(all_tmp.begin(), all_tmp.end());
    std::sort(all.begin(), all.end());
    std::sort(lefts.begin(), lefts.end());
    ll answer =0 ;

    int next_number = 1;
    // all ex) 1 3 4 5 6 7
    // lefts ex) 1 5
    while (!all.empty()) {
        int cur = all.front(); all.pop_front();
        if (cur == next_number) {
            next_number++;
            continue;
        } else if (cur < next_number) {
            continue;
        } else { // 맨 앞에 있는 숫자가 필요한 숫자보다 클 때
            // 방금 뽑았던 값 다시 넣기
            all.push_front(cur);
            // left number을 이용해서 제거 하고, 그게 안되면 맨 뒤 숫자를 이용해서 제거
            bool fin = false;
            while (!lefts.empty()) {
                int left_first = lefts.front(); lefts.pop_front();
                int gap = left_first-next_number;
                if (gap < 0) {
                    continue;
                } else {
                    answer+=gap;
                    fin= true;
                    break;
                }
            }
            // 남은 것들로는 부족할 때
            if (!fin) {
                if (!all.empty()) {
                    int back = all.back(); all.pop_back();
                    int gap = back-next_number;
                    answer+=gap;
                }
            }
            next_number++;
        }
    }
    cout << answer;

}