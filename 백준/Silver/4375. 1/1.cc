#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while (cin >> n) {
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}
		int ans;
		int bf1 = 1%n;
		int bf2 = 10%n;
		int count = 2;
		while (true) { // n = 7
			ans = (bf2 % n + bf1 % n) % n; 
			if (ans == 0) break;
			bf1 = ans;
			bf2 = ((bf2 % n) * (10 % n)) % n;
			count++;
		}
		cout << count << "\n";
	}
}


