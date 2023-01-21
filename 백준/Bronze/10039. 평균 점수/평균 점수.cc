#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n,sum=0;
	for (int i = 1; i <= 5; i++) {
		cin >> n;
		if (n < 40) n = 40;
		sum += n;
	}
	cout << sum / 5;
}