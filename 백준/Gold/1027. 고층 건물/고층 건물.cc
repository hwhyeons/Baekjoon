#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <sstream>
#include <deque>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> v;

bool can_see(int start, int end) {
	// start와 end사이를 잇는 직선을 침범하는 경우 >> 불가능
	int x1, x2, y1, y2;
	if (start > end) {
		swap(start, end);
	}
	x1 = start;
	x2 = end;
	y1 = v[start];
	y2 = v[end];

	double lin = ((double)(y2 - y1)) / (x2 - x1);
	bool ok = true;
	for (int i = start + 1; i < end; i++) {
		if (lin * (i - x1) + y1 <= v[i]) { // 하나라도 겹친다면
			ok = false;
			break;
		}
	}
	return ok;
}


// 한 좌표에서 몇개를 볼 수 있는지
int get_count(bool left, int index) {
	int x = index;
	int y = v[index];
	int count = 0;
	if (left) {
		for (int i = index - 1; i >= 0; i--) {
			if (can_see(index, i)) count++;
		}
	}
	else {
		for (int i = index+1; i < v.size(); i++) {
			if (can_see(index, i)) count++;
		}
	}
	return count;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int count, t;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> t;
		v.push_back(t);
	}
	int ans = -1;
	for (int i = 0; i < v.size(); i++) { // 각 빌딩별
		int lcount = get_count(true,i);
		int rcount = get_count(false,i);
		ans = max(ans, lcount + rcount);
	}
	cout << ans;
}


