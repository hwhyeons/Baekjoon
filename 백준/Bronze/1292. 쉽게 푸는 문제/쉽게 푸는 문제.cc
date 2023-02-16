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
	int a,b;
	cin >> a >> b;
	vector<int> v;
	v.push_back(0); // 임시 값
	for (int i = 1; i<=1000; i++) {
		for (int j =0; j<i; j++) {
			v.push_back(i);
		}
	}
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum += v[i];
	}
	cout << sum;

}


