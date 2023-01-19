#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	int i = 0;
	while (v.size() >= 1) {
		i = (i + k-1) % (v.size());
		ans.push_back(v[i]);
		v.erase(v.begin() + i);
	}

	cout << "<";
	for (int i = 0; i < ans.size()-1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[ans.size() - 1] << ">";
}