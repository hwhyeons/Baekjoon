#include <bits/stdc++.h>
#include <ranges>
typedef long long ll;
typedef long double ld;
using namespace std;

class Node {
public:
    int start;
    int end;
    ll boxCnt;

    bool operator<(const Node& other) const {
        if (this->end == other.end) {
            return this->start>other.start;
        }
        return this->end<other.end;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,C,M;
    cin >> N >> C >> M;
    vector<Node> v;
    for (int i=0;i<M;i++) {
        int s,e,bc;
        cin >> s >> e >> bc;
        v.push_back({s,e,bc});
    }
    ll answer = 0ll;
    sort(v.begin(),v.end());
    deque<Node> finishList; // 실제 정답에 기여하는 대상
    vector<ll> maxValue(N+1);
    for (Node& node : v) {
        // if (copyList.front().end <= point) copyList.pop_front();
        // for (Node& use : finishList) {
        //     acc += use.boxCnt;
        // }
        ll maxAcc = 0ll;
        for (int k=node.start;k<node.end;k++) {
            maxAcc = max(maxAcc,maxValue[k]);
        }
        if (maxAcc >= C) {
            continue;
        }
        // 쓸 수 있는 경우
        ll useCount = min(C - maxAcc,node.boxCnt);

        finishList.push_back({node.start,node.end,useCount});
        answer+= useCount;
        for (int k=node.start;k<node.end;k++) {
            maxValue[k] += useCount;
        }
    }
    cout << answer;

}