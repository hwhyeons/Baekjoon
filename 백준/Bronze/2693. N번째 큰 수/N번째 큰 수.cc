#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	for (int i =0;i<n;i++)
	{
		int t;
		for (int j=0;j<10;j++) {
			cin >> t;
			v.push_back(t);
		}
		sort(v.begin(),v.end(),[](auto &a, auto &b){return a>b;});
		cout << v[2] << "\n";
		v.clear();
	}
	
}


