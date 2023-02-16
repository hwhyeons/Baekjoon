#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <numeric>
#include <deque>
#include <stack>
#include <unordered_set>

using namespace std;

int arr[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int sum = 0;
	for (int i =0; i<10;i++) {
		int t;
		cin >> t;
		sum += t;
		arr[t/10] += 1;
	}
	cout << sum/10 << "\n";
	int maxIdx = 0;
	for (int i =0 ;i<100; i++) {
		if (arr[i] > arr[maxIdx]) {
			maxIdx = i;
		}
	}
	cout << maxIdx*10;

}


