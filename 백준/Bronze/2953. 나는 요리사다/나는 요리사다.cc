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

	int max = 0, m_idx = 0;
	for (int i = 0; i < 5; i++) {
		int sum = 0,tmp;
		for (int j = 0; j < 4;j++) {
			cin >> tmp;
			sum += tmp;
		}
		if (sum > max) {
			m_idx = i + 1;
			max = sum;
		}
	}
	cout << m_idx << " " << max;
}