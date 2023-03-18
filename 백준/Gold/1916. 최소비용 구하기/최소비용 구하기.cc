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

using namespace std;
#define vc vector
#define inf 1000000000

class Node{
    public:
        int idx;
        int value;

        bool operator<(const Node& n) const {
            return this->value > n.value;
        }

        Node(int idx, int value) : idx(idx),value(value){};
};

int dik(vc<vc<int>> v, int start, int end) {
    vc<int> mn(v[start].size(),inf);
    mn[start] = 0;
    priority_queue<Node> pq;
    pq.push({start,0});
    while (!pq.empty()) {
        Node node = pq.top(); pq.pop(); // min node
        int idx = node.idx;
        int val = node.value;
        if (val > mn[idx]) continue;
        for (int i =0;i<mn.size();i++) {
            int next_dist = v[idx][i] + val;
            if (next_dist < mn[i]) {
                mn[i] = next_dist;
                pq.push({i,mn[i]});
            }
        }
    }
    return mn[end];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin >> n >> m;
    vc<vc<int>> v(n,vc<int>(n));
    for (int i =0; i<n;i++) {
        for (int j =0;j<n;j++) {
            if (i==j) v[i][j] = 0;
            else v[i][j] = inf;
        }
    }
    for (int i =0;i<m;i++) {
        int a,b,c;
        cin >>a>>b>>c;
        v[a-1][b-1] = min(v[a-1][b-1],c);
    }
    int start,end;
    cin >> start >> end;
    if (start == end) {
        cout << 0;
    } else {
        int answer = dik(v,start-1,end-1);
        cout << answer; 
    }
    
}