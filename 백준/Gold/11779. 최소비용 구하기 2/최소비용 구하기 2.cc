#include <bits/stdc++.h>

#define ll long long


using namespace std;

void dik(vector<vector<ll>>& dist,int start, int end) {
    vector<ll> mins(dist.size(), 1200000000);
    vector<bool> visit(dist.size());
    vector<int> before_node_idx(dist.size());
    mins[start] = 0;
    int cur_idx = start;
    while (true) {
        visit[cur_idx] = true;
        ll cur_val = mins[cur_idx];

        // 갱신
        for (int i = 1; i < dist.size(); ++i) {
            if (cur_val + dist[cur_idx][i] < mins[i] && !visit[i]) {
                mins[i] = cur_val + dist[cur_idx][i];
                before_node_idx[i] = cur_idx;
            }
        }

        int next_idx = -1;
        ll mn_val = 1300000000;
        for (int i = 1; i < mins.size(); ++i) {
            if (visit[i]) continue;
            if (mins[i] < mn_val) {
                mn_val = mins[i];
                next_idx = i;
            }
        }
        if (next_idx == -1) {
            break;
        }
        cur_idx = next_idx;
    }

    // 재귀로 경로 역추적
    int re_s = end;
    vector<int> ans_nodes;
    while (true) {
        ans_nodes.push_back(re_s);
        int before_move = before_node_idx[re_s];
        if (before_move == start) {
            ans_nodes.push_back(start);
            break;
        }
        re_s = before_move;
    }
    // min answer
    cout << mins[end] << endl;

    // path cnt
    cout << ans_nodes.size() << endl;

    // path
    for (int i = ans_nodes.size() - 1; i >= 0; --i) {
        cout << ans_nodes[i] << " ";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; // node cnt
    cin >> n >> m;
    vector<vector<ll>> w(n+1,vector<ll>(n+1,1200000000));
    for (int i = 0; i < m; ++i) {
        int t1,t2;
        ll t3;
        cin >> t1 >> t2 >> t3;
        w[t1][t2] = min(t3, w[t1][t2]);
    }
    for (int i = 1; i <= n; ++i) {
        w[i][i] = 0;
    }
    int start,end;
    cin >> start >> end;
    if (start == end) {
        cout << 0 << endl << 1 << endl << start;
        return 0;
    }
    dik(w,start,end);
}




