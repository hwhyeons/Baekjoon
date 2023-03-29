#include <bits/stdc++.h>
#include <ranges>

#define ll long long
#define inf INT_MAX
#define rv ranges::views

using namespace std;


ll dik(vector<vector<ll>>& dist, int start, int end) {
    vector<ll> mins(dist.size(), INT_MAX);
    mins[start] = 0;
    priority_queue<pair<ll,int>> pq; // pair : {-min_dist / index}
    pq.push({0,start});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int cur_idx = p.second;
        ll cur_dist = -p.first;
        if (cur_dist > mins[cur_idx]) continue;
        for (int i = 1; i < dist.size(); ++i) {
            if (mins[i] > cur_dist + dist[cur_idx][i]) {
                mins[i] = cur_dist + dist[cur_idx][i];
                pq.push({-mins[i],i});
            }
        }
    }
    return mins[end];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m;
    cin >> n>>m;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1,INT_MAX));
    for (int i = 0; i < m; ++i) {
        int t1,t2,t3;
        cin >>t1>>t2>>t3;
        dist[t1][t2] = t3;
        dist[t2][t1] = t3;
    }
    int start,end;
    cin >> start >> end;
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    // middle distance
    ll mid = dik(dist, start, end);
    if (mid == INT_MAX) {
        cout << -1;
        return 0;
    }
    long long tmp1 = dik(dist, 1, start);
    long long tmp2 = dik(dist, n, end);
    long long tmp3 = dik(dist, n, start);
    long long tmp4 = dik(dist, 1, end);
    if ((tmp1 == INT_MAX || tmp2 == INT_MAX) && (tmp3 == INT_MAX || tmp4 == INT_MAX)) {
        cout << -1;
        return 0;
    }
    ll first = min(tmp1 + tmp2, tmp3 + tmp4);
    cout << first+mid;
}
