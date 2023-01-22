#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, tmp;
	cin >> n;
	
	deque<pair<int, int>*> d;
	for (int i = 1;i <= n;i++) {
		cin >> tmp;
		pair<int, int>* p = new pair<int, int>;
		pair<int, int> pTmp = make_pair(i, tmp);
		*p = pTmp;
		d.push_back(p);
	}

	pair<int, int>* p;
	while (d.size() > 0) {
		p = d.front();
		d.pop_front();
		cout << (*p).first << " ";
		int move = (*p).second;
		if (d.size() == 0) break;
		if (move > 0) {
			for (int j = 1; j < move; j++) {
				p = d.front();
				d.pop_front();
				d.push_back(p);
			}
		}
		else {
			move = -move;
			for (int j = 1; j <= move; j++) {
				p = d.back();
				d.pop_back();
				d.push_front(p);
			}
		}
	}
}


