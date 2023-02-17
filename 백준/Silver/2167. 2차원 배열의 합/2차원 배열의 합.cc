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

int k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	int** arr = new int*[n];
	// vector<vector<int>> arr(n,vector<int>(m));
// 
	for (int i =0; i<n; i++) {
		arr[i] = new int[m];
		for (int j =0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
	int k,i,j,x,y;
	cin >> k;


	for (int row =0; row<k; row++) {
		cin >> i >> j >> x >> y;
		int sum = 0;
		for(int t =i; t<=x; t++) {
			for (int t2 = j; t2 <= y; t2++) {
				sum += arr[t-1][t2-1];
			}
		}
		cout << sum << "\n";
	}

}


