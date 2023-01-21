#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <unordered_set>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	unordered_set<int> s;
	int n,t;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> t;
		s.insert(t);
	}

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> t;
		if (s.find(t) != s.end()) cout << "1\n";
		else cout << "0\n";
	}


}