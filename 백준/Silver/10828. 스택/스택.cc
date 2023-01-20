#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <stack>
#include <set>
#include <queue>


using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n,n2;
	string t;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == "push") {
			cin >> n2;
			s.push(n2);
		}
		else if (t == "pop") {
			if (s.empty()) cout << "-1\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (t == "size") {
			cout << s.size() << "\n";
		}
		else if (t == "empty") {
			cout << s.empty() << "\n";
		}
		else {
			if (s.empty()) cout << "-1\n";
			else cout << s.top() << "\n";
		}
	}
}