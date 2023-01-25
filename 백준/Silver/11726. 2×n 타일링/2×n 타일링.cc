#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


#define MOD 10007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n+1,0);
	v[1] = 1;
	if (n+1>2) v[2] = 2;
	for (int i = 3; i<=n; i++) {
		v[i] = (v[i-1]%MOD + v[i-2]%MOD)%MOD;
	}
	cout << v[n];
}





