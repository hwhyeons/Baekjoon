#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int f(int n) {
	if (n <= 1) {
		return 1;
	} else {
		return n*f(n-1);
	}
}

int main() {
	int n;
	cin >> n;
	n = f(n);
	cout << n;
}





