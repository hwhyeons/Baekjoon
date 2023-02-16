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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[42];
	fill(arr,arr+42,0);
	for (int i =0;i<10;i++)
	{
		int t;
		cin >> t;
		arr[t%42] += 1;
	}
	int diffCount = 0;
	for (int i =0;i <42;i++) {
		if (arr[i] != 0) {
			diffCount++;
		}
	}
	cout << diffCount;
}


