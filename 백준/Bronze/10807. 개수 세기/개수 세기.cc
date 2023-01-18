#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s;

	int count;
	cin >> count;
	int arr_plus[101] = {};
	int arr_minus[101] = {};
	int tmp;
	for (int i = 0; i < count;i++) {
		cin >> tmp;
		if (tmp > 0) {
			arr_plus[tmp] += 1;
		}
		else {
			arr_minus[-tmp] += 1;
		}
	}
	int ans;
	cin >> ans;
	if (ans > 0) {
		cout << arr_plus[ans];
	}
	else {
		cout << arr_minus[-ans];
	}
	
}