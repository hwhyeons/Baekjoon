#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

void comb(vector<int>& v,vector<int>& out, int idx, int depth) {
	if (depth == 6) {
		auto it = out.begin();
		while (it != out.end()) {
			cout << *it << " ";
			it++;
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < v.size();i++) {
		out[depth] = v[i];
		comb(v, out, i + 1, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	while (true) {
		cin >> n;
		if (n == 0) break;
		vector<int> v(n);
		vector<int> out(6);
		for (int i = 0;i < n;i++) {
			cin >> t;
			v[i] = t;
		}
		sort(v.begin(), v.begin() + n);
		comb(v, out,0,0);
		cout << "\n";
	}
}

