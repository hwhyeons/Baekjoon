#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <deque>
#include <stack>
#include <unordered_set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	string t;
	while (true) {
		getline(cin,t);
		stack<char> s;
		if (t == ".") return 0;
		bool ok = true;
		for (int i =0; i<t.size(); i++) {
			if (t[i] == '(' || t[i] == '[') {
				s.push(t[i]);
			} else if (t[i] == ']' || t[i] == ')') {
				if (s.empty()) {
					ok = false;
					break;
				}
				if (t[i] == ']' && s.top() == '[') {
					s.pop();
				} else if (t[i] == ')' && s.top() == '('){
					s.pop();
				} else {
					ok = false;
					break;
				}
			} else {
				continue;
			}
		}
		if (ok && s.empty()) {
			cout << "yes" << "\n";
		} else {
			cout << "no" << "\n";
		}
	}
}


