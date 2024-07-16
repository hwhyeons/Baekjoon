#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <numeric>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include<bitset>
#include <map>
#include <vector>
#include <stack>
#include <ranges>

using namespace std;

unordered_map<int, int> m; // 특정 번호의 인덱스 위치
vector<int> v; // 기본 벡터

pair<int, int> initSegment(vector<pair<int, int>>& seg, int index, int start, int end) {
	if (start == end) {
		int number = v[start - 1];
		if (number % 2 == 0) seg[index] = { 1,0 }; // 짝수인지 여부
		else seg[index] = { 0,1 };
		if (m.find(start) != m.end()) throw "error - already contains";
		m[start] = index;
		return seg[index];
	}
	int mid = (start + end) / 2;
	pair<int, int> childCntLeft = initSegment(seg, index * 2, start, mid);
	pair<int, int> childCntRight = initSegment(seg, index * 2 + 1, mid + 1, end);
	seg[index] = { childCntLeft.first + childCntRight.first, childCntLeft.second + childCntRight.second };
	return seg[index];
}

void redraw(vector<pair<int, int>>& seg, int segIdx) {
	if (segIdx == 0) { // 원소 하나인 경우 고려
		return;
	}
	auto [l1, r1] = seg[segIdx * 2];
	auto [l2, r2] = seg[segIdx * 2 + 1];
	seg[segIdx] = { l1 + l2,r1 + r2 };
	if (segIdx > 1) { // 0번이거나 1번이 아니면
		redraw(seg, segIdx / 2);
	}
}

// 특정 인덱스 값을 바꾸기
void change(int idx, int changeValue, vector<pair<int, int>>& seg) {
	int realIndex = m[idx]; // segment array index
	if (changeValue % 2 == 0) {
		seg[realIndex] = { 1,0 };
	}
	else {
		seg[realIndex] = { 0,1 };
	}
	redraw(seg, realIndex / 2);
}

int getAnswer(vector<pair<int, int>>& seg, int idx, int realStart, int realEnd, int wantStart, int wantEnd, bool isEven) {
	// 범위초과 처리
	if (wantEnd < realStart) return 0;
	if (realEnd < wantStart) return 0;

	// isEven : 짝수인지
	// 범위가 원하는 것 안에 포함되는 경우. 예를들어 4~9(wantEnd)을 원하는데 현재위치에서 5~6을 표현
	if (wantStart <= realStart && realEnd <= wantEnd) {
		return isEven ? seg[idx].first : seg[idx].second;
	}
	// 3~6을 원하는 상황인데 현재 표현값이 0~5인 경우
	// 3~6을 원하는 상황인데 현재 표현값이 2~4인 경우
	int midIdx = (realStart + realEnd) / 2;
	int leftAnswer = getAnswer(seg, 2 * idx, realStart, midIdx, wantStart, wantEnd, isEven);
	int rightAnswer = getAnswer(seg, 2 * idx + 1, midIdx + 1, realEnd, wantStart, wantEnd, isEven);
	return leftAnswer + rightAnswer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	vector<pair<int, int>> seg(4 * N);
	initSegment(seg, 1, 1, N);

	int queryCount;
	cin >> queryCount;
	for (size_t i = 0; i < queryCount; i++)
	{
		int type;
		cin >> type;
		if (type == 1) {
			int idx, changeValue;
			cin >> idx >> changeValue;
			change(idx, changeValue, seg);
		}
		else if (type == 2) {
			int l, r;
			cin >> l >> r;
			cout << getAnswer(seg, 1, 1, N, l, r, true) << "\n";
		}
		else if (type == 3) {
			int l, r;
			cin >> l >> r;
			cout << getAnswer(seg, 1, 1, N, l, r, false) << "\n";
		}

	}

}