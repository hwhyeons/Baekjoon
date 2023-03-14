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
#include <limits.h>
#include <queue>
#define ll long long

using namespace std;

int end_p = 0;

/*
void dfs(int idx, int time) {
    if (idx >= v.size() || idx < 0) return;
    if (v[end_p] <= time) return; //  최소를 넘어선 경우 볼 필요 없이 리턴
    else if (v[idx] <= time) return; //
    else if (idx > end_p && idx-end_p+time>v[end_p]) return; // 뒤로 가는게 희망이 없을 때
    v[idx] = time;
    v[end_p] = min(v[end_p],time+abs(idx-end_p));
    if (idx != 0) dfs(idx*2,time);
    dfs(idx-1,time+1);
    dfs(idx+1,time+1);
}
*/

queue<pair<int,int>> q; // (인덱스,시간)
void bfs(vector<int>& v,int startPoint) { // v : 시간 벡터
    q.push({startPoint,0});
    while (!q.empty()) {
        int index = q.front().first;
        int time = q.front().second;
        q.pop();
        if (time >= v[index]) continue;
        else v[index] = time; // 최소 시간 갱신
        if (index != 0) {
            int next_index = index*2;
            while (next_index < v.size()) {
                q.push({next_index,time});
                next_index *= 2;
            }
        }
        if (index +1 < v.size()) q.push({index+1,time+1});
        if (index - 1 >= 0) q.push({index-1,time+1});
    }
    cout << v[end_p];
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    end_p = b;
    vector<int> v(200000,INT_MAX);
    if (b <= a) {cout << a-b; return 0;}
    bfs(v,a);
}