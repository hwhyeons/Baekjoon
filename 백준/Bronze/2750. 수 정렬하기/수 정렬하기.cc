#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <stack>
#include <set>


using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	set<int,less<int>> s;
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		s.insert(t);
	}
	for (auto i = s.begin(); i != s.end(); i++) {
		cout << *i << "\n";
	}
}