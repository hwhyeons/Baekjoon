#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int i =0;
	vector<string> v;
	while (i++ < n) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	if (v[0].size() == 1) {
		cout << "1";
		return 0;
	}
	for (int j =1; j<=v[0].size(); j++){
		unordered_set<string> set;
		for (int k =0; k<v.size(); k++) {
			set.insert(v[k].substr(v[k].size()-j,j));
		}
		if (set.size() == n) {
			cout << j;
			break;
		}
	}
}
