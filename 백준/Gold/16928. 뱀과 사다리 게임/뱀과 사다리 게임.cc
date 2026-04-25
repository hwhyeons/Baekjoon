// #include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ranges>
#include<deque>
#include <limits>
#include <set>
#include <map>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> rs(101); // 로프랑 뱀

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        int ta,tb;
        cin >> ta >> tb;
        rs[ta] = tb;
    }
    for (int i=0;i<M;i++) {
        int ta,tb;
        cin >> ta >> tb;
        rs[ta] = tb;
    }

    vector<bool> visit(101);
    deque<pair<int,int>> d; // {현재좌표, 굴린횟수}
    d.push_front({1,0});
    // visit[1] = true;
    // int minAcc = 0;
    while (!d.empty()) {
        auto [curPos, acc] = d.front(); d.pop_front();
        // if (acc < minAcc) throw "err";
        // minAcc = acc;
        if (curPos == 100) {
            cout << acc;
            return 0;
        }
        if (visit[curPos]) continue;
        visit[curPos] =  true;
        if (rs[curPos]) {
            // visit[rs[curPos]] = true;
            d.push_front({rs[curPos],acc});
            continue;
        }

        for (int gap=1;gap<=6; gap++) {
            int nextPos = curPos+gap;
            if (nextPos > 100) break;
            if (nextPos == 100) {
                cout << acc+1;
                return 0;
            }
            d.push_back({nextPos,acc+1});
        }
    }
}