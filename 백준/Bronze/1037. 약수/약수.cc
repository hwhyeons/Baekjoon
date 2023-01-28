#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,t,m1=INT_MAX,m2=-1;
	cin >> n;
	for (int i =0; i<n; i++) {
		cin >> t;
		m1 = min(m1,t);
		m2 = max(m2,t);
	}
	cout << m1*m2;
}





