#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;


bool isPrime(int n){
	if (n == 1) return false;
	int bound = (int)sqrt(n);
	for (int i = 2; i<=bound; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin >> a >> b;
	vector<int> v(b+1);
	for (int i = a; i<=b;i++) {
		v[i] = i;
	}
	
	for (int i = a; i<=b; i++) {
		if (i == 1) continue;
		if (v[i] == -1) continue;
		if (isPrime(v[i])) {
			cout << v[i] << "\n";
		}
		for (int j = 2*i; i<=b; j++) {
			long long rmv = ((long long)v[i])*j;
			if (rmv > b) break;
			v[rmv] = -1;
		}
		v[i] = -1;
	}
}

