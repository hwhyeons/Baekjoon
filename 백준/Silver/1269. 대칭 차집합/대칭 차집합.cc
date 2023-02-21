#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin >> a >> b;
	set<int> s1;
	set<int> s2;
	for (int i =0;i<a; i++) {
		int t;
		cin >> t;
		s1.insert(t);
	}

	for (int i =0;i<b; i++) {
		int t;
		cin >> t;
		s2.insert(t);
	}
	
	vector<int> buffer1(s1.size()+s2.size());
	vector<int> buffer2(s1.size()+s2.size());
	auto it1 = set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),buffer1.begin());
	auto it2 = set_difference(s2.begin(),s2.end(),s1.begin(),s1.end(),buffer2.begin());
	cout << (it1-buffer1.begin()) + (it2-buffer2.begin());
}
	


