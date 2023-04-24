#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;


vector<int> parents;
int get_parent(int idx) { // 최적화 유니온 파인드
    if (parents.at(idx) == idx) return idx;
    else {
        parents.at(idx) = get_parent(parents.at(idx));
        return parents.at(idx);
    }
}

void merge(int idx1, int idx2) {
    int p1 = get_parent(idx1);
    int p2 = get_parent(idx2);
    if (p1 == p2) return; // 이미 그룹화 되어 있는 경우
    else {
        if (p1 > p2) {
            parents.at(p1) = parents.at(p2);
        } else {
            parents.at(p2) = parents.at(p1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    parents.assign(n+1,0);
    iota(parents.begin(), parents.end(),0);
    for (int i = 0; i < m; ++i) {
        int order;
        cin >> order;
        int t1,t2;
        cin >> t1 >> t2;
        if (order == 0) {
            merge(t1,t2);
        } else { // order == 1
            int p1 = get_parent(t1);
            int p2 = get_parent(t2);
            if (p1 == p2) {
                cout << "YES";
            } else {
                cout << "NO";
            }
            cout << "\n";
        }

    }
}