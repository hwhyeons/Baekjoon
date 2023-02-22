#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>

#define ll long long
#define inf 2200000000ll

using namespace std;

class edge {
public:
	int n1,n2;
	int w;
};

vector<edge> v;
vector<int> parent;


int find(int node) {
	if (parent[node] == node) {
		return node;
	} else {
		return find(parent[node]);
	}
}

void union_node (int n1, int n2){
	int p1 = find(n1);
	int p2 = find(n2);
	parent[max(p1,p2)] = parent[min(p1,p2)];
}


void mst(int vertexCount) {
	int answer = 0;
	int count = 0;
	int idx = 0;
	for(;;) {
		auto edge = v[idx];
		int p1 = find(edge.n1);
		int p2 = find(edge.n2);
		if (p1 != p2) {
			union_node(p1,p2);
			answer += edge.w;
			count++;
			if (count == vertexCount-1) break;
		}
		idx++;
	}
	cout << answer;
}

bool compare(edge& e1, edge& e2) {
	return e1.w < e2.w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int V,E;
	cin >> V >> E;
	int a,b,c;
	for (int i =0; i<E; i++) {
		cin >> a >> b >> c;
		edge e;
		e.n1 = a;
		e.n2 = b;
		e.w = c;
		v.push_back(e);
	}
	parent.push_back(-1);
	for (int i =0; i<V; i++) {
		parent.push_back(i+1); // 처음에는 자기 자신
	}
	sort(v.begin(),v.end(),compare);
	mst(V);
}
	


