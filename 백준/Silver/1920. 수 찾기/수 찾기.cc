#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>


using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	for (int i =0; i<n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(),v.end());

	int m;
	cin >> m; 
	for (int i =0; i<m; i++) {
		int t;
		cin >> t;
		if (binary_search(v.begin(),v.end(),t)) {
			cout << "1\n";
		}  else {
			cout << "0\n";
		}
	}
}
	


