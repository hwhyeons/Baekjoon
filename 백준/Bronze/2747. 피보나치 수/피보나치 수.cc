#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int arr[46];

int f(int n) {
	if (n <= 1) {
		return n;
	} else {
        if (arr[n] != 0) {
            return arr[n];
        }
        int k = f(n-1) + f(n-2);
        arr[n] = k; 
		return k;
	}
}

int main() {
	int n;
	cin >> n;
	n = f(n);
	cout << n;
}





