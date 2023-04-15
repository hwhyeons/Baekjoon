#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt_crane; cin >> cnt_crane;
    vector<int> mx_weight;
    for (int i = 0; i < cnt_crane; ++i) {
        int t;
        cin >> t;
        mx_weight.push_back(t);
    }
    std::sort(mx_weight.begin(), mx_weight.end(), greater<int>());
    int cnt_box; cin >> cnt_box;
    vector<int> all_box;
    for (int i = 0; i < cnt_box; ++i) {
        int t; cin >> t;
        all_box.push_back(t);
    }
    vector<deque<int>> crane(cnt_crane);
    std::sort(all_box.begin(), all_box.end(),greater<int>());
    // 가장 무거운 박스가 가장 무거운 크레인보다 무겁다면
    if (all_box.front() > mx_weight.front()) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < all_box.size(); ++i) {
        int cur_weight = all_box[i];
        for (int j = mx_weight.size()-1; j >= 0; --j) {
            if (cur_weight > mx_weight[j]) continue;
            else {
                crane.at(j).push_back(cur_weight);
                break;
            }
        }
    }

    int left_cnt = cnt_box;

    int time = 1;
    // 순서대로 시작
    while (true) {
        // 각각의 크레인마다 처리
        for (int i = 0; i < crane.size(); ++i) {
            deque<int>& dq = crane[i];
            // 만약 처리할게 없다면 뒤쪽 크레인에서 가져오기
            if (dq.empty()) {
                for (int j = i+1; j < crane.size(); ++j) {
                    deque<int> &ndq = crane[j];
                    if (ndq.empty()) continue;
                    else {
                        ndq.pop_front();
                        left_cnt--;
                        if (left_cnt == 0) {
                            cout << time;
                            return 0;
                        }
                        break;
                    }
                }
            } else {
                dq.pop_front();
                left_cnt--;
                if (left_cnt == 0) {
                    cout << time;
                    return 0;
                }
            }
        }
        time++;
    }


}