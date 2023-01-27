#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,t;
	cin >> n;
	int* arr = new int[n];
	for (int i =0; i<n; i++) {
		cin >> t;
		arr[i] = t;
	}
	sort(arr,arr+n);
	for (int i =0; i<n; i++) {
		cout << arr[i] << "\n";
	}
}





