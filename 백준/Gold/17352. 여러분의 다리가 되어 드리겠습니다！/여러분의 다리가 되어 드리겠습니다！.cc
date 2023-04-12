#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;



vector<int> vp; // {노드 번호 / 부모}

int get_parent(int idx) {
    if (vp[idx] == idx) {
        return idx;
    }
    int p = vp[idx];
    return vp[idx] = get_parent(p);
}


void merge(int p1, int p2) {
    int parent1 = get_parent(p1);
    int parent2 = get_parent(p2);
    if (parent1 == parent2) return;
    if (parent1 < parent2) {
        vp[parent2] = parent1;
    } else {
        vp[parent1] = parent2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vp.assign(n+1,0);
    iota(vp.begin(), vp.end(),0); // 자기 자신을 부모로
    for (int i = 0; i < n-2; ++i) {
        int t1,t2;
        cin >> t1 >> t2;
        merge(t1,t2);
    }

    int p_idx = vp[1];
    for (int i = 2; i <= n; ++i) {
        int tmp = get_parent(i);
        if (tmp != p_idx) {
            cout << tmp << " " << p_idx;
            return 0;
        }
    }
}