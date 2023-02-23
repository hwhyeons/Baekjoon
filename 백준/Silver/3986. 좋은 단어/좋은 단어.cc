#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int i = 0;
	int cnt = 0;
	cin >> n;
	while (i++ < n) {
		string s;
		cin >> s;
		stack<char> st;
		bool ok = true;
		for (int j =0; j<s.size();j++) {
			char t = s[j];
			if (st.empty()) {
				st.push(t);
			} else {
				if (st.top() == t) {
					st.pop();
				} else {
					st.push(t);
				}
			}
		}

		while (!st.empty()) {
			char t1 = st.top();
			st.pop();
			if (st.empty()) {
				ok = false;
				break;
			} else {
				if (st.top() == t1) {
					st.pop();
				} else {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			cnt++;
		}
	}
	cout << cnt;
}
