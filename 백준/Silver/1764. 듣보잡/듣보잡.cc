#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <deque>
#include <unordered_set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	string t;
	cin >> n >> k;
	unordered_set<string> s;
	for (int i =0;i<n;i++) {
		cin >> t;
		s.insert(t);
	}
	vector<string> ans;
	int cnt = 0;
	for (int i =0;i<k;i++) {
		cin >> t;
		if (s.find(t) == s.end()) { // ok
			continue;
		} else {
			cnt++;
			ans.push_back(t);
		}
	}

	sort(ans.begin(),ans.end());
	cout << cnt << endl;
	for (auto i = ans.begin(); i != ans.end(); i++) {
		cout << *i << "\n";
	}
}


