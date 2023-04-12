#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;


unordered_map<int,int> parent_map; // {행성 번호, 부모 행성 번호}
unordered_map<int,ll> group_count; // {그룹의 조상 행성 번호 , 집합의 전체 행성의 개수}


int get_parent(int idx) {
    if (parent_map[idx] == idx) {
        return idx;
    }
    int p = parent_map[idx];
    return parent_map[idx] = get_parent(p);
}

ll merge_and_get_count(int p_idx1, int p_idx2) {
    int parent1 = get_parent(p_idx1);
    int parent2 = get_parent(p_idx2);
    if (parent1 == parent2) { // already in same group
        return group_count[parent1];
    } else {
        ll g1_member_cnt = group_count[parent1];
        ll g2_member_cnt = group_count[parent2];
        if (parent1 < parent2) {
            group_count.erase(parent1);
            parent_map[parent1] = parent2;
            group_count[parent2] = g1_member_cnt + g2_member_cnt;
        } else {
            group_count.erase(parent2);
            parent_map[parent2] = parent1;
            group_count[parent1] = g1_member_cnt + g2_member_cnt;
        }
        return g1_member_cnt+g2_member_cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        ll cnt;
        cin >> cnt;
        group_count[i] = cnt;
        parent_map[i] = i; // 자기 자신이 부모
    }

    for (int i = 0; i < M; ++i) {
        int t1,t2;
        cin >> t1 >> t2;
        ll cnt = merge_and_get_count(t1,t2);
        cout << cnt << "\n";
    }


}