#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <unordered_map>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	unordered_map<int,int> m;
	int n,t;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> t;
		if (m.find(t) == m.end()) {
			m.insert({ t,1 });
		}
		else {
			m[t] = (*(m.find(t))).second + 1;
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		auto it = m.find(t);
		if (it == m.end()) {
			cout << "0 ";
		}
		else {
			cout << (*it).second << " ";
		}
	}

}