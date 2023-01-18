#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i]-'0';
	}
	cout << sum;
}