#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <queue>


using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	priority_queue<int> s;
	s.push(a);
	s.push(b);
	s.push(c);
	int ans;
	s.pop();
	cout << s.top();
}