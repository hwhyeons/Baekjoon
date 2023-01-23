#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <sstream>
#include <deque>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T, n;
	cin >> T;
	for (int i = 0; i < T;i++) {
		cin >> n;
		char tmp;
		deque<char> d;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			if (d.empty() || tmp <= d.front()) {
				d.push_front(tmp);
			}
			else {
				d.push_back(tmp);
			}
		}
		for (auto it = d.begin(); it != d.end(); it++) {
			cout << *it;
		}
		cout << "\n";
	}
}

