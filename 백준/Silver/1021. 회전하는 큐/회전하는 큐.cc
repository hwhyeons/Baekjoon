#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	deque<int> d;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}
	int findNumber; // 찾고자 하는 수
	int sum = 0;
	for (int i = 0; i < m; i++) {
		cin >> findNumber;
		int lastIndex = d.size();
		int findIdx = find(d.begin(), d.end(), findNumber) - d.begin();
		int gap = lastIndex - findIdx;
		if (findIdx < gap) { // 앞에거를 뒤로 미루는게 나은 경우
			for (int j = 1; j <= findIdx; j++) { // 만나기 전까지 미루기
				int tmp = d.front();
				d.pop_front();
				d.push_back(tmp);
			}
			sum += findIdx;
		}
		else { // 뒤에거를 앞으로 땡기는게 나은 경우
			for (int j = 1; j <= gap; j++) {
				int tmp = d.back();
				d.pop_back();
				d.push_front(tmp);
			}
			sum += gap;
		}
		// 뽑았으니 제거
		d.pop_front();
	}
	cout << sum;
}