#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int  u, d, h, c = 0;
	cin >> u >> d >> h;
	int k = (h-u) / (u - d);
	int r = (h - u) % (u - d);
	if (r != 0) {
		k++;
	}
	cout << k + 1;

}