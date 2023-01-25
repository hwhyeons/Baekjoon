#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t_count,k,n;
	cin >> t_count;
	for (int i =1; i<=t_count; i++) {
		cin >> k >> n;
		int** arr = new int*[k+1];
		arr[0] = new int[n+1];
		for (int j = 1; j <= n; j++) { // floor 0
			arr[0][j] = j;
		}
	
		for (int j = 1; j<=k; j++) { // k층 (1층부터 시작)
			arr[j] = new int[n+1];
			arr[j][0] = 0;
			for (int l = 1; l<=n; l++) {
				arr[j][l] = arr[j-1][l] + arr[j][l-1];
			}
		}
		cout << arr[k][n] << "\n";
		delete[] arr;
	}
}





