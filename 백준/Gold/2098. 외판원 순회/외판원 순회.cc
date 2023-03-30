#include <bits/stdc++.h>
#include <ranges>

#define ll long long

using namespace std;

int n;

// 특정 비트가 1인지 체크
bool is_one(int bits, int pos) {
    int test = 1 << pos;
    return bits & test;
}

int set_bit(int path, int idx, int zero_one) {
    if (zero_one) { // set 1
        path = path | 1 << (idx);
    } else {
        path = path & (1 << (idx));
    }
    return path;
}

bool is_end(int path) {
    for (int i = 0; i < n; ++i) {
        if (!is_one(path,i)) return false;
    }
    return true;
}

ll tsp(vector<vector<ll>>& v, vector<vector<ll>>& mem, int curIdx, int before_visit_path) {
    // if mem
    if (mem[curIdx][before_visit_path] != -1) {
        return mem[curIdx][before_visit_path];
    }

    // no mem
    int add_cur_visit_path = set_bit(before_visit_path,curIdx,1); // curIdx번째 비트를 1로 전환

    if (is_end(add_cur_visit_path)) {
        return v[curIdx][0]; // 시작노드
    }

    ll mn = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        if(is_one(add_cur_visit_path,i)) continue; // 이미 방문한 노드
        if(v[curIdx][i] == 0) continue; // 무한대의 경우
        ll path_w = tsp(v,mem,i,add_cur_visit_path);
        if (path_w != 0) {
            mn = min(path_w+v[curIdx][i],mn);
        }
    }
    if (mn == LLONG_MAX) mn = 0; // 경로가 없으므로 0리턴
    mem[curIdx][before_visit_path] = mn;
    return mn;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;
    vector<vector<ll>> v(n,vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> mem(n,vector<ll>((ll)powl(2,n),-1)); // row : 현재 인덱스 / col : 비트 마스킹 방문
    cout << tsp(v,mem,0,0);
}

