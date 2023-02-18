#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int mi=10000000,mx=-10000000;
	for(int i = 0; i<n; i++) {
		int tmp;
		cin >> tmp;
		mi = min(mi,tmp);
		mx = max(mx,tmp);
	}
	cout << mi << " " << mx;
	
}


