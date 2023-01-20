#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <stack>
#include <queue>


using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int c,tmp;
	cin >> c;
	stack<int> s;
	for (int i	= 0; i < c;i++) {
		cin >> tmp;
		if (tmp == 0) {
			s.pop();
		}
		else {
			s.push(tmp);
		}
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;

}