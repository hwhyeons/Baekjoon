#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int h, m, n;
	cin >> h >> m >> n;
	m = h * 60 + m;
	m += n;
	h = m / 60;
	m = m % 60;
	if (h >= 24) h -= 24;
	cout << h << " " << m;
}