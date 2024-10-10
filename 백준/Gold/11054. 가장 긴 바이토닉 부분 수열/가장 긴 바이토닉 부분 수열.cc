#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> dpAsc(N,1);
	vector<int> dpDesc(N,1);
	for (size_t i = 0; i < N; i++) {
		cin >> v[i];
	}
	
	// 좌하향 DP
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				dpAsc[i] = max(dpAsc[j] + 1, dpAsc[i]);
			}
		}
	}
	
	// 우하향 DP
	for (int i = N-1; i >= 0; i--) {
		for (size_t j = i+1; j < N; j++) {
			if (v[j] < v[i]) {
				dpDesc[i] = max(dpDesc[j] + 1, dpDesc[i]);
			}
		}
	}
	
	// 좌하향 선택 -> 다음인덱스부터 좌상향 최대 선택
	int bestAnswer = 1;
	for (int i = 0; i < N; i++) {
		int leftBestLen = dpAsc[i];
		// 좌상향 찾기
		for (int j = i + 1; j < N; j++) {
			if (v[j] < v[i]) {
				bestAnswer = max(bestAnswer, leftBestLen + dpDesc[j]);
			}
		}
	}

	cout << bestAnswer;


}