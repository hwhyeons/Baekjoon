#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;

class node {
public:
	int val;
	int parent_x;
	int parent_y;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, t;
	cin >> n >> m;
	vector<int> v(n); // 누적합 벡터
	vector<int> idx(m);
	vector<int> sum(m); // 마지막 그룹
	cin >> t;
	v[0] = t;
	for (int i = 1;i < n;i++) {
		cin >> t;
		v[i] = t + v[i - 1];
	}
	for (int i = 0; i < m;i++) {
		idx[i] = i;
	}

	if (n == 1) {
		cout << v[0] << "\n1";
		return 0;
	}
	else if (m == 1) {
		cout << v[n - 1] << "\n" << n;
		return 0;
	}

	vector<int> answer(m);
	int min_ = 1000000000;
	while (true) {
		for (int i = 0; i < m; i++) {
			if (i == m - 1) {
				sum[i] = v[v.size() - 1] - v[idx[i] - 1];
			}
			else if (i == 0) {
				sum[i] = v[idx[i + 1] - 1];
			}
			else {
				sum[i] = v[idx[i + 1] - 1] - v[idx[i] - 1];
			}
		}
		auto max_it = max_element(sum.begin(), sum.end());
		int max_val = *max_it;
		int argmax = max_it - sum.begin();
		if (max_val < min_) { // 결과 저장
			min_ = max_val;
			for (int i = 0; i < idx.size(); i++) {
				answer[i] = idx[i];
			}
		}
		if (argmax == 0) break;
		if ((argmax == sum.size() - 1 && idx[argmax]+1 == v.size()) || (argmax != sum.size()-1 && (idx[argmax] + 1 == idx[argmax + 1]))) break;
		idx[argmax] += 1;
	}
	cout << min_ << "\n";

	for (int i = 1; i < answer.size(); i++) {
		cout << answer[i] - answer[i - 1] << " ";
	}
	cout << v.size() - answer[answer.size() - 1];

}
