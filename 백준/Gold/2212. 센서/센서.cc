#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <numeric>
#include <unordered_set>


using namespace std;

bool compare(int& a, int& b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k,t;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n;i++) {
		cin >> t;
		v.push_back(t);
	}
	if (n == 1 && k == 1 || k>=n) {
		cout << 0;
		return 0;
	}
	sort(v.begin(), v.end());
	vector<int> gap;
	for (int i = 0; i < n - 1; i++) {
		gap.push_back(v[i + 1] - v[i]);
	}
	sort(gap.begin(), gap.end(),compare);
	int sum = accumulate(gap.begin(), gap.begin() + k-1,0);
	int min = v[0];
	int max = v[v.size() - 1];
	int answer = max - min - sum;
	cout << answer;
}
