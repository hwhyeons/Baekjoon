#include <bits/stdc++.h>
#include <ranges>

#define ll long long
#define inf INT_MAX
#define rv ranges::views

using namespace std;

class node {

public:
    int idx;
    bool visit =false;
    ll min = inf;
    node(int idx) : idx(idx) {}
};

struct cmp {
    bool operator()(const pair<int,ll>& p1,pair<int,ll>& p2) const {
        return p1.second > p2.second;
    }
};
ll dik(vector<vector<ll>>& dist,vector<vector<int>>& adj, int start, int end) {
    vector<ll> mins(dist.size(),INT_MAX);
    mins[start] = 0;
    priority_queue<pair<int,ll>,vector<pair<int,ll>>,cmp> pq; // pair : {인덱스 / 최소 거리}
    pq.push({start,0LL});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int cur_idx = p.first;
        ll cur_dist = p.second;
        if (mins[cur_idx] < cur_dist) continue;
        for (int i = 0; i < adj[cur_idx].size(); ++i) {
            int adj_idx = adj[cur_idx][i];
            if (cur_dist+dist[cur_idx][adj_idx] < mins[adj_idx]) {
                mins[adj_idx] =cur_dist+dist[cur_idx][adj_idx];
                pq.push({adj_idx,mins[adj_idx]});
            }
        }
    }
    return mins[end];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,x; // node cnt
    cin >> n >> m >> x;
    vector<vector<ll>> dist(n+1,vector<ll>(n+1,INT_MAX));
    vector<vector<int>> adj(n+1); // (번호 / 인접 노드들)
    for (int i = 0; i < m; ++i) {
        int t1,t2,t3; cin >> t1>>t2>>t3;
        dist[t1][t2] = t3;
        adj[t1].push_back(t2);
    }
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }
    ll mx = -100;
    for (int i = 1; i <= n; ++i) {
        if (i == x) continue;
        ll go = dik(dist,adj, i, x); // 가는데 걸리는 시간
        ll ret = dik(dist,adj, x, i); // 오는데 걸리는 시간
        mx = max(mx, go+ret);
    }
    cout << mx;
}




