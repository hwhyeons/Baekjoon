#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	int arr[26];
	fill_n(arr, 26, -1);
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		int idx = c - 'a';
		if (arr[idx] == -1) {
			arr[idx] = i;
		}
		else {
			continue;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}