#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <stack>
#include <queue>


using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int,vector<int>,greater<int>> pq;
	int n,t;
	cin >> n;
	while (cin >> n) {
		if (n == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}
	*/
}