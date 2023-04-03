#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

struct cmp {
    bool operator()(const pair<int,int>& p1,const pair<int,int>& p2) const {
        if (p1.second == p2.second) {
            return p1.first > p2.second;
        } else {
            return p1.second < p2.second;
        }
    }
};

priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;


void push_all_time(int want_time, unordered_map<int,vector<int>>& s) {
    if (!s.contains(want_time)) return;
    vector<int>& v2 = s[want_time];
    for (int a : v2) {
        pq.push({want_time,a});
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    unordered_map<int,vector<int>> s_time;
    int mx_time = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        int t1,t2;
        cin >> t1>>t2;
        if (s_time.contains(t1)) {
            s_time[t1].emplace_back(t2);
        } else {
            s_time[t1] = vector<int>();
            s_time[t1].emplace_back(t2);
        }
        mx_time = max(mx_time,t1);
    }

    int cur_time = mx_time;
    int answer = 0;
    // pair : {time, value}
    while (cur_time > 0) {
        push_all_time(cur_time,s_time);
        if (pq.empty()) {
            cur_time--;
            continue;
        }
        auto best = pq.top(); pq.pop();
        answer += best.second;
        cur_time--;
    }
    cout << answer;
}