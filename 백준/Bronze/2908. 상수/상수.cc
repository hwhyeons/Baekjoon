#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	string s1, s2;
	s1 = to_string(a);
	s2 = to_string(b);
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	a = stoi(s1);
	b = stoi(s2);
	if (a > b) {
		cout << a;
	}
	else {
		cout << b;
	}
}