#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a,b,c;
	cin >> a >> b >> c;
	int n = a * b * c;
	string s = to_string(n);
	int len = s.length();
	int arr[11] = {};
	for (int i = 0; i < len; i++) {
		arr[s[i]-'0'] += 1;
	}
	for (int i = 0; i <= 9; i++) {
		cout << arr[i] << "\n";
	}
}