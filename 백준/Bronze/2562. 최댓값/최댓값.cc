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

	int tmp,max=-1,m_idx=-1;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		if (tmp > max) {
			max = tmp;
			m_idx = i+1;
		}
	}
	cout << max;
	cout << "\n" << m_idx;
}