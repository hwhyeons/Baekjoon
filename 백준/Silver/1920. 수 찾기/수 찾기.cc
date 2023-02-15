#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <numeric>
#include <deque>
#include <stack>
#include <unordered_set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a,b,t;
	vector<int> v;
	cin >> a;
	for (int i =0; i<a; i++) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	

	
	cin >> b;
	for (int i =0; i<b; i++) {
		cin >> t;
		int s =0,e=v.size()-1,m;
		bool ok = false;
		while (s<=e) {
			m = (s+e)/2;
			if (v[m] == t) {
				ok = true;
				break;
			}
			if (v[m] < t) {
				s = m+1;
			} else {
				e = m - 1;
			}
		}
		if (ok) {
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	}
}


