#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int ans;
	int count = 0;
	cin >> ans;
	int n = ans;
	while (true) {
		count++;
		n = (n % 10) * 10 + (n / 10 + n % 10) % 10;
		if (n == ans) break;
	}
	cout << count;
}