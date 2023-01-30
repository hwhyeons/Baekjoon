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
	string* v = new string[n];
	for (int i = 0; i < n;i++) {
		cin >> t;
		v[i] = t;
	}
	sort(v, v+n,compare);
	string* u_ptr = unique(v, v+n);
	for (int i = 0; i < n; i++) {
		if (u_ptr == &v[i]) break;
		cout << v[i] << "\n";
	}
}
