#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n,t;
	cin >> n;
	int cur = 2;
	stack<int> s;
	s.push(1);
	vector<string> v; // answer vector
	v.push_back("+");
	for (int i = 1; i <= n;i++) {
		cin >> t;
		while (true) {
			if (s.empty() || s.top() < t) {
				if (cur > t) {
					cout << "NO";
					return 0;
				}
				v.push_back("+");
				s.push(cur);
				cur++;
			}
			else if (s.top() == t) {
				v.push_back("-");
				s.pop();
				break;
			}
			else {
				v.push_back("-");
				s.pop();
				cur++;
			}
		}
	}
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << "\n";
	}

}

