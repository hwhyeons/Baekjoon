#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcnt;
    cin >> tcnt;
    while (tcnt--) {
        int cnt_student;
        cin >> cnt_student;
        vector<int> v(cnt_student+1);
        vector<bool> vis(cnt_student+1);
        vector<int> dest(cnt_student+1,-1); // 최종 목적지
        for (int i = 1; i <= cnt_student; ++i) {
            cin >> v[i];
        }
        int answer_left = 0;
        for (int i = 1; i <= cnt_student; ++i) {
            if (vis[i]) continue;
            unordered_set<int> cur_visit;
            vis[i] = true;
            cur_visit.insert(i);

            int start_point = i;
            int next = v[start_point];
            vector<int> order;

            order.push_back(start_point);
            while (true) {
                if (next == start_point) { // 시작한 곳에서 되돌아 온 경우
                    answer_left+=cur_visit.size();
                    break;
                }
                // 1->5->2->3->5->2처럼 1에서 출발했지만 중간 노드끼리 그룹화 되는 경우
                if (cur_visit.contains(next)) {
                    int group_start_idx = find(order.begin(), order.end(),next)-order.begin();
                    // group_start_idx부터 끝까지에 있는 개수 만큼만 그룹에 추가
                    answer_left += order.size()-group_start_idx;
                    break;
                } else if (vis[next]) {
                    // 중간 노드끼리 만나는 것도 아닌데 이미 방문한 곳을 만나는 경우
                    // ex) 1->4->"2->3->6->5->1"에서 2부터 시작했을 때 1은 이미 방문한 노드 >> 2부터 5까지는 모두 그룹에 속하지 못함
                    break;
                }
                vis[next] = true;
                order.push_back(next);
                cur_visit.insert(next);
                next = v[next];
            }
        }
        cout << cnt_student - answer_left << "\n";
    }
}