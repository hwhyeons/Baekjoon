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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t_count,a,b;
	cin >> t_count;
	for (int i = 0; i < t_count; i++) {
		cin >> a >> b;
		int ans = 1;
		for (int j = 1; j <= b; j++) {
			ans = (ans * a%10) % 10;
		}
		if (ans == 0) ans = 10;
		cout << ans  << "\n";
	}
}


