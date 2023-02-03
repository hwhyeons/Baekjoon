#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int cnt = 0;
	cin >> n;
	for (int i =0; i<n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 1) continue;
		int bound = (int)sqrt(tmp);
		cnt++;
		for (int j =2; j<= bound; j++) {
			if (tmp%j == 0) {
				cnt--;
				break;
			}
		}
	}
	cout << cnt;
}

