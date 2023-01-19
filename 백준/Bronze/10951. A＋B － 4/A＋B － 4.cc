#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	while (cin >> a >> b) {
		cout << a + b << "\n";
	}
}