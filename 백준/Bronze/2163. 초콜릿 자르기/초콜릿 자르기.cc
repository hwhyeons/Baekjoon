#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	cout << a * b - 1;
}