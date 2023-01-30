#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;


bool compare(string& a, string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string t;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n;i++) {
		cin >> t;
		v[i] = t;
	}
	sort(v.begin(), v.end(),compare);
	auto u = unique(v.begin(), v.end());
	if (u != v.begin()) v.erase(u,v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}
