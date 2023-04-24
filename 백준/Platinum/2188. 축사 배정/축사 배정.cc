#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

class Barn {
public:
    int idx;
    bool is_cow_inside = false; // 소가 들어있는 경우 true
    int inside_cow_idx=-1; // barn에 들어있는 소 번호
};

class Cow {
public:
    int idx;
    vector<int> want_barn_idxs; // 원하는 축사 번호
};

vector<Barn> barns;
vector<Cow> cows;

//int answer = 0;
//// 넣었으면 -1, 실패했으면 실패 인덱스
//int dfs(int cur_cow_idx, int acc) {
//    answer = max(acc,answer);
//    if (cur_cow_idx == cows.size()) return -1;
//    Cow &cow = cows.at(cur_cow_idx);
//    bool child_success = false;
//    for (int want_barn_idx : cow.want_barn_idxs) {
//        Barn& want_barn = barns[want_barn_idx];
//        if (want_barn.is_cow_inside) continue; // 해당 축사에 소가 들어있는 경우
//        want_barn.is_cow_inside = true;
//        bool ok = dfs(cur_cow_idx+1,acc+1);
//        if (!ok) {
//            want_barn.vis = false;
//            continue;
//        } else {
//            child_success = true;
//            break;
//        }
//    }
//    // 전부 다 돌았는데도 실패시, 그 이전 노드에게 다른 노드를 선택하라고 명령
//    if (child_success) {
//        return cur_cow_idx+1;
//    } else {
//        return -1;
//    }
//}

bool dfs(int cur_cow_idx){
    Cow &cow = cows.at(cur_cow_idx);
    for (int want_barn_idx : cow.want_barn_idxs) {
        Barn& want_barn = barns[want_barn_idx];
        if (want_barn.is_cow_inside) continue; // 이미 해당 축사에 소가 들어있는 경우
        want_barn.is_cow_inside = true;
        if (want_barn.inside_cow_idx == -1 || dfs(want_barn.inside_cow_idx)) {
            want_barn.inside_cow_idx = cur_cow_idx;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    barns.assign(M+1,Barn());
    cows.assign(N+1,Cow());

    for (int i = 1; i <= N; ++i) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int tmp;
            cin >> tmp;
            cows[i].want_barn_idxs.push_back(tmp);
        }
    }

    // 1번 소부터 시작
    for (int i = 1; i <= N; ++i) {
        // 방문 초기화
        for (int j = 1; j <= M; ++j) {
            barns[j].is_cow_inside = false;
        }
        dfs(i);
    }
    int answer = 0;
    for (int i = 1; i <= M; ++i) {
        if (barns.at(i).inside_cow_idx > 0) answer++;
    }
    cout << answer;

}