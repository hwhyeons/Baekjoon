#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	set<int> s;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	int ans;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
}