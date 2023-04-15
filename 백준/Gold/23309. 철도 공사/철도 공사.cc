#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N >> M;
    unordered_map<int,pair<int,int>> map; // { 역 : {이전역 / 다음역}}
    vector<int> tmps;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        tmps.push_back(t);
    }
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            pair<int,int> ptmp = make_pair(tmps.back(),tmps.at(1));
            map[tmps[0]] = ptmp;
        } else if (i == N-1) {
            pair<int,int> ptmp = make_pair(tmps.at(N-2),tmps.front());
            map[tmps[N-1]] = ptmp;
        } else {
            pair<int,int> ptmp = make_pair(tmps.at(i-1),tmps.at(i+1));
            map[tmps[i]] = ptmp;
        }
    }

    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        if (s == "BN") {
            int t1,t2;
            cin >> t1 >> t2;
            cout << map[t1].second << "\n";
            pair<int,int> new_station = make_pair(t1,map[t1].second);
            map[map[t1].second].first = t2;
            map[t1].second = t2;
            map[t2] = new_station;
        } else if (s == "BP") {
            int t1,t2;
            cin >> t1 >> t2;
            cout << map[t1].first << "\n";
            pair<int,int> new_station = make_pair(map[t1].first,t1);
            map[map[t1].first].second = t2;
            map[t1].first = t2;
            map[t2] = new_station;
        } else if (s == "CN") {
            int t;
            cin >> t;
            int next = map[t].second;
            int next_next = map[map[t].second].second;
            map[t].second = next_next;
            map[next_next].first = t;
            map.erase(next);
            cout << next << "\n";
        } else if (s == "CP") {
            int t;
            cin >> t;
            int prev = map[t].first;
            int prev_prev = map[map[t].first].first;
            map[t].first = prev_prev;
            map[prev_prev].second = t;
            map.erase(prev);
            cout << prev << "\n";
        }
    }

}