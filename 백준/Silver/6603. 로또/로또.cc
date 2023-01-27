#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, t;
	while (true) {
		cin >> n;
		if (n == 0) break;
		vector<int> v(n);
		for (int i = 0;i < n;i++) {
			cin >> t;
			v[i] = t;
		}
		vector<int> idxs(n);
		sort(v.begin(), v.begin() + n);
		fill(idxs.begin(), idxs.begin() + 6, 1);
		do {
			for (int i = 0; i < idxs.size(); i++) {
				if (idxs[i] == 1) cout << v[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(idxs.begin(),idxs.end()));
		cout << "\n";	
	}
}
