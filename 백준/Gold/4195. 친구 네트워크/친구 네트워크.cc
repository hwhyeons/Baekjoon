#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;


unordered_map<string,string> parent_map; // {이름 , 부모}
unordered_map<string,int> group_count; // {그룹장 이름 , 멤버의 개수}




string get_parent(string s) {
    if (!parent_map.contains(s)) {
        parent_map[s] = s;
        group_count[s] = 1;
        return s;
    } else if (parent_map[s] == s) {
        return s;
    }
    string p = parent_map[s];
    return parent_map[s] = get_parent(p);
}

int merge_and_get_count(string s1, string s2) {
    string parent1 = get_parent(s1);
    string parent2 = get_parent(s2);
    if (parent1 == parent2) { // already in same group
        return group_count[parent1];
    } else {
        int g1_member_cnt = group_count[parent1];
        int g2_member_cnt = group_count[parent2];
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
    int tcnt;
    cin >> tcnt;
    while (tcnt--) {
        int relation_cnt;
        cin >> relation_cnt;
        for (int i = 0; i < relation_cnt; ++i) {
            string s1,s2;
            cin >> s1 >> s2;
            int cnt = merge_and_get_count(s1,s2);
            cout << cnt << "\n";
        }
        group_count.clear();
        parent_map.clear();
    }
}