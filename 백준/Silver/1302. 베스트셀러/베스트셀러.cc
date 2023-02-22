#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_map<string,int> m;
	vector<string> mv; // max vector
	int curMax = 0;
	for (size_t i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		if (!m.count(t)) {
			m[t] = 1;
		} else {
			m[t] += 1;
		}
		int val = m[t];
		if (val > curMax) {
			curMax = val;
			mv.clear();
			mv.push_back(t);
		} else if (val == curMax) {
			mv.push_back(t);
		}
	}
	sort(mv.begin(), mv.end());
	cout << mv[0];
	
	
}
	


