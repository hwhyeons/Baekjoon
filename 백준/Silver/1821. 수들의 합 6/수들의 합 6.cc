#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <deque>
#include <set>


using namespace std;


bool finish = false;

bool correct(int ans, vector<int> v) {
	if (v.size() == 1) {
		return v[0] == ans;
	}
	vector<int> nv;
	for (int i =0; i<v.size()-1; i++) {
		nv.push_back(v[i]+v[i+1]);
	}
	return correct(ans,nv);
}


void permutation(vector<int>& v, vector<bool>& visited,int depth, int ans)
{
	if (finish) return;
	if (depth == v.size()) {
		if (correct(ans,v)) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i]<<" ";
			}
			finish = true;
		}
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v[depth] = i + 1;
			permutation(v,visited,depth + 1,ans);
			v[depth] = 0;
			visited[i] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,f;
	cin >> n >> f;
	if (n == 1) {
		cout << f;
		return 0;
	}

	vector<int> v(n);
	vector<bool> visited(n);


	
	permutation(v,visited,0,f);


}


