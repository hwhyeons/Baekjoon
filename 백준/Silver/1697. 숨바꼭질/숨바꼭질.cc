#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

struct cmp {
    bool operator()(const pair<int,int>& p1,const pair<int,int>& p2) const {
        return p1.first > p2.first;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> mins(200001,200000000); // 시간

    // 다익스트라
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({0,n});
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
        // 간선 : 세개
        int cur_idx= tp.second;
        if (tp.first > mins[cur_idx]) {
            continue;
        }
        mins[cur_idx] = tp.first;
        if (cur_idx -1 >= 0) {
            if (tp.first + 1 < mins[cur_idx-1]) {
                pq.push({tp.first+1,cur_idx-1});
            }
        }
        if (cur_idx + 1 < mins.size()) {
            if (tp.first + 1 < mins[cur_idx+1]) {
                pq.push({tp.first+1,cur_idx+1});
            }
        }
        if (cur_idx != 0 && cur_idx*2 < mins.size()) {
            if (tp.first + 1 < mins[cur_idx*2]) {
                pq.push({tp.first+1,cur_idx*2});
            }
        }
    }
    cout << mins[k];

}