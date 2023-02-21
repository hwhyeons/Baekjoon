#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define pair pair<int,string>

bool compare(pair p1, pair p2) {
	if (p1.first < p2.first) {
		return true;
	} else {
		return false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair> v;
	int n;
	cin >> n; 
	for (int i=0;i<n; i++)
	{
		int t1;
		string t2;
		cin >> t1 >> t2;
		v.push_back({t1,t2});
	}
	stable_sort(v.begin(),v.end(),compare);

	auto it = v.begin();
	while (it != v.end()) {
		cout << (*it).first << " " << (*it).second << "\n";
		it++;
	}



}
	


