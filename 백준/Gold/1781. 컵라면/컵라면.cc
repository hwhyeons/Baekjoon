#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

vector<int> ps; // parents

int findParent(int);

void merge(int i1, int i2) {
    int p1 = findParent(i1);
    int p2 = findParent(i2);
    if (p1 < p2) {
        ps[i2] = p1;
        ps[i1] = p1; // -1이 들어갈 수 있기 때문에 해야함
    } else {
        ps[i1] = p2;
        ps[i2] = p2;
    }
}

int findParent(int idx) {
    if (ps[idx] == idx) {
        return idx;
    } else {
        return ps[idx] = findParent(ps[idx]);
    }
}
vector<ll> ansV;
void setBestIndex(int dead,ll cup) {
    if (ps[dead] == dead && ansV[dead] == 0) { // 시작 부터 바로
        ansV[dead] = cup;
        if (dead+1< ps.size() && ansV.at(dead+1) != 0) {
            merge(dead,dead+1);
        }
        if (dead >= 2 && ansV.at(dead-1) != 0) {
            merge(dead,dead-1);
        }
        return;
    }
    int parent = findParent(dead);
    if (parent >= 2) {
        ansV.at(parent-1) = cup;
        merge(parent-1,parent);
        if (parent-1>=2 && ansV.at(parent-2) != 0) merge(parent-1,parent-2);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ps.assign(n+1,-1); // -1 : 비어있는 공간
    ansV.assign(n+1,0);
    iota(ps.begin(), ps.end(),0);

    priority_queue<pair<ll,ll>> pq;
    for (int i = 0; i < n; ++i) {
        ll t1,t2; cin >> t1 >> t2;
        pq.emplace(t2,-t1);
    }

    while (!pq.empty()) {
        auto [cup,dead] = pq.top();
        pq.pop();
        dead *= -1;
        setBestIndex(dead,cup);
    }
    cout << accumulate(ansV.begin()+1, ansV.end(),0ll); // 0번 인덱스 제외
}