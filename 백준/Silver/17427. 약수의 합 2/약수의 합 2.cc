#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 1; i<=n; i++) {
		sum += i*(n/i);
	}
	cout << sum;
}

