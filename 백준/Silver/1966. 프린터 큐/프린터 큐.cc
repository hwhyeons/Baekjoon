#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <numeric>
#include <deque>
#include <stack>
#include <unordered_set>
#define pair  pair<int,int> 

using namespace std;



struct cmp 
{
	bool operator()(pair& p1, pair& p2) {
		if (p1.second < p2.second) {
			return true;
		} else {
			return false;
		}
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testCount;
	int n,c;
	cin >> testCount;
	for (int i =0; i<testCount; i++)
	{
		cin >> n >> c;
		queue<pair> q;
		priority_queue<pair,vector<pair>, cmp> pq;
		// 전부 다 추가
		for (int j =0; j<n; j++) {
			int prior;// 중요도
			cin >> prior;
			pair p({j,prior}); // 
			q.push(p);
			pq.push(p);
		}

		int printCount = 0;
		while (!q.empty()) {
			auto topQ = q.front();
			auto best = pq.top();
			if (topQ.second != best.second) {
				q.push(topQ);
				q.pop();
			} else {
				printCount++;
				pq.pop();
				q.pop();
				if (topQ.first == c) {
					cout << printCount << "\n";
					break;
				}
			}
		}
	}
}


