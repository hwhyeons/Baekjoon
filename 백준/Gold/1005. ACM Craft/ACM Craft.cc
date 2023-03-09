#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <queue>

using namespace std;

long long get_best_time(int idx, vector<int>& best_time,vector<int>& time, vector<vector<int>>& node) {
    if (best_time[idx] != -1) { // 이미 계산 된 경우
        return best_time[idx];
    }
    long long acc = 0LL;
    for (int f =0; f<node[idx].size(); f++) {
        acc = max(acc,get_best_time(node[idx][f],best_time,time,node));
    }
    acc += time[idx];
    best_time[idx] = acc;
    return acc;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t_case;
    cin >> t_case;
    while (t_case--){
        int N,K;
        cin >> N >> K;
        vector<int> time(N+1);
        vector<vector<int>> node(N+1); // 노드 , 선조건
        for (int i =1; i<=N; i++) {
            int tmp;
            cin >> tmp;
            time[i] = tmp;
        }
        for (int i=0; i<K; i++) {
            int a,b;
            cin >> a >> b;
            node[b].push_back(a);
        }

        int winBuilding;
        cin >> winBuilding;

        // dfs 시작 : 모든 노드들 순회
        vector<int> best_time(N+1,-1); // -1로 초기화 (-1이면 방문 X)
        int answer = get_best_time(winBuilding,best_time,time,node);
        cout << answer << "\n";
    }

}