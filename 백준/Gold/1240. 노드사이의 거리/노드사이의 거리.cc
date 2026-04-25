#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ranges>
// #include<bits/stdc++.h>
#include <limits>
typedef long long ll;
typedef long double ld;
using namespace std;


class Node {
public:
	unordered_map<int,ll> adjs; // Node번호, 이웃거리
	int depth;
	int parent;
};


ll dfs(vector<Node>& v,int curNodeNum, int findNodeNum, ll acc, int parentNum) {
	Node& node = v[curNodeNum];
	if (node.adjs.find(findNodeNum) != node.adjs.end()) {
		return acc+node.adjs[findNodeNum];
	}

	ll ansLocal = -1;
	for (auto p : node.adjs) {
		if (p.first ==parentNum) continue;
		ansLocal =dfs(v,p.first,findNodeNum,acc+p.second,curNodeNum);
		if (ansLocal != -1) break;
	}

	if (ansLocal == -1) return -1;
	return ansLocal;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin >> N >> M;
	vector<Node> v(N+1);
	for (int i = 0; i < N-1; ++i) {
		int a,b,c;
		cin >> a >> b >> c;
		v[a].adjs[b] = c;
		v[b].adjs[a] = c;
	}
	for (int i=0; i<M; i++) {
		int wantA,wantB;
		cin >> wantA >> wantB;
		if (wantA == wantB) cout << 0 << "\n";
		cout << dfs(v,wantA,wantB,0ll,0) << "\n";
	}
}