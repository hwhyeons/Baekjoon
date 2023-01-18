#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s;
	getline(cin, s);
	stringstream ss(s);
	string tmp;
	vector<string> v;
	while (getline(ss,tmp,' ')) {
		v.push_back(tmp);
	}
	int ans = 0;
	if (s[0] == ' ') {
		ans++;
	}
	cout << v.size()-ans;
}