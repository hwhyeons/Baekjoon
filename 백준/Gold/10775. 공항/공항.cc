#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;

vector<int> parent; // key : 게이트 번호 / value : 부모노드
vector<bool> used; // 게이트를 썼는지

int findParent(int node) {
    if (node == parent[node]) return node;
    else {
        int p = parent[node];
        return parent[node] = findParent(p); // 최적화 유니온 파인드
    }
}


void merge(int n1, int n2) {
    int p1 = findParent(n1);
    int p2 = findParent(n2);
    if (p1 < p2) {
        parent[p2] = p1;
    } else {
        parent[p1] = p2;
    }
}

int findBestAndCheck(int node) {
    int p = findParent(node);
    if (!used[p]) {
        used[p] = true;
        return p;
    }
    // 이미 사용 중인 경우 + 제일 앞 노드
    if (p == 1) {
        return 0;
    }
    // 새로운 노드와 병합
    int np = findBestAndCheck(p - 1);
    if (np == 0) return 0;
    if (np > p) throw "err";
    // 병합
    merge(np, p);
    return np;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int G, P;
    cin >> G >> P;
    used.assign(G+1, false);
    for (size_t i = 0; i <= G; i++) {
        parent.push_back(i); // 처음에는 자기 자신이 부모
    }

    int answer = 0;
    for (size_t i = 0; i < P; i++) {
        int gi; cin >> gi;
        int rt = findBestAndCheck(gi);
        if (rt == 0) {
            break;
        }
        answer++;
        continue;
    }
    cout << answer;
}