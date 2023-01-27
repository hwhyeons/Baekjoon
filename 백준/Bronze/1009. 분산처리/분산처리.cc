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

// 재귀 함수
// 나누는 값은 무조건 10
int f(int a, int n) {
	if (n == 1) {
		return a % 10;
	}

	if (n % 2 == 0) { // 짝수
		return (((f(a, n / 2)) % 10) * ((f(a, n / 2)) % 10)) % 10;
	}
	else { // 홀 수
		return (((((f(a, n / 2)) % 10) * ((f(a, n / 2)) % 10)) % 10) * (a % 10)) % 10;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t_count,a,b;
	cin >> t_count;
	for (int i = 0; i < t_count; i++) {
		cin >> a >> b;
		int ans = f(a, b);
		if (ans == 0) ans = 10;
		cout << ans  << "\n";
	}
}


