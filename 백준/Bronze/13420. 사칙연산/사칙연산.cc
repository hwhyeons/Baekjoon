#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	ll a, b,c;
	string s1, s2;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> s1 >> b >> s2 >> c;
		bool tf = false;
		if (s1 == "+") {
			if (a + b == c) tf = true;
		}
		else if (s1 == "-") {
			if (a - b == c) tf = true;
		}
		else if (s1 == "*") {
			if (a * b == c) tf = true;
		}
		else {
			if (a / b == c) tf = true;
		}
		if (tf) {
			cout << "correct\n";
		}
		else {
			cout << "wrong answer\n";
		}
	}
}