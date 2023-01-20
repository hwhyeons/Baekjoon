#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <stack>
#include <queue>


using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n,tmp;
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> pq;
	int size = n * n;
	for (int i = 0;i < size; i++) {
		cin >> tmp;
		if (pq.size() == n) {
			if (tmp > pq.top()) {
				pq.pop();
				pq.push(tmp);
			}
		}
		else {
			pq.push(tmp);
		}
	}
	cout << pq.top();
}