#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	deque<int> d;
	for (int i = 0;i < n;i++) {
		d.push_back(i);
	}
	vector<int> v(n, 0);
	int t = 1;
	while (d.size() > 0) {
		int tmp;
		for (int i = 1; i <= t; i++) {
			tmp = d.front();
			d.pop_front();
			d.push_back(tmp);
		}
		tmp = d.front(); // 인덱스
		v[tmp] = t;
		d.pop_front();
		t++;
	}

	for (auto i = v.begin(); i != v.end(); i++) {
		cout << *i << " ";
	}

}