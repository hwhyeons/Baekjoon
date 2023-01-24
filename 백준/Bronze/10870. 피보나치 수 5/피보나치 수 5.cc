#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int f(int n) {
	if (n <= 1) {
		return n;
	} else {
		return f(n-1) + f(n-2);
	}
}

int main() {
	int n;
	cin >> n;
	n = f(n);
	cout << n;
}





