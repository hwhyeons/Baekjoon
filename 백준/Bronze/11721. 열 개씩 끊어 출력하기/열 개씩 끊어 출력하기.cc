#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i =0; i<s.length(); i++) {
		if (cnt == 10) {
			cnt = 0;
			cout << "\n";
		}
		cout << s[i];
		cnt++;
	}
}
	


