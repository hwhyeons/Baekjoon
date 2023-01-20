#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <map>
#include <unordered_set>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	unordered_set<string> set;
	int n, m;
	string t;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> t;
		set.insert(t);
	}

	int ans = 0;
	for (int i = 0;i < m;i++) {
		cin >> t;
		if (set.find(t) != set.end()) {
			ans++;
		}
	}
	cout << ans;
}