#include <bits/stdc++.h>

#define ll long long

using namespace std;


int mx_tmp_idx;
ll mx = 0LL;
bool fin = true;
int idx2;
// v : 간선 정보
ll get_dist(vector<unordered_map<int,ll>>& v, vector<bool>& visit,int n, int idx, ll acc){
    visit[idx] = true;
    auto& friends = v[idx];
    if (acc > mx) {
        mx = max(acc,mx);
        mx_tmp_idx = idx;
    }
    ll mx2 = 0LL;
    for (auto &fr: friends) {
        if (visit[fr.first]) continue;
        ll tmp = get_dist(v, visit, n, fr.first, acc + fr.second);
        mx2 = max(mx2,tmp);
    }
    return mx+acc;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; // node cnt
    cin >> n;
    vector<unordered_map<int,ll>> v(n+1); // (node number : {key : LinkedNodeNumber / val : dist})
    for (int i = 0; i < n; ++i) {
        int node_number; cin >> node_number;
        auto& cur_set = v[node_number];
        while (true) {
            int link_node_num;
            cin >> link_node_num;
            if (link_node_num == -1) break;
            ll link_node_dist;
            cin >> link_node_dist;
            cur_set[link_node_num] = link_node_dist;
        }
    }

    vector<bool> visit(n+1);
    ll dist =  get_dist(v,visit,n,1,0LL);
    idx2 = mx_tmp_idx;
    visit = vector<bool>(n+1);
    dist =  max(dist,get_dist(v,visit,n,mx_tmp_idx,0LL));
    cout << dist;
}




