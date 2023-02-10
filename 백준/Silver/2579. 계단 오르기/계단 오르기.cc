#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp_o(n);
	vector<int> dp_x(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	dp_o[0] = v[0];
	dp_x[0] = 0;
	if (n >= 2) {
		dp_o[1] = v[1]+v[0];
		dp_x[1] = v[0];
	}

	if (n >= 3) { // OXO or XOO
		dp_o[2] = v[2]+max(v[0],v[1]);
		dp_x[2] = v[0] + v[1];
	}

	for (int i =3; i<n; i++) {
		// 이번 턴에 먹는 경우
		// 1. i-1에 먹고 i-2에 안먹고 i-3에 먹기
		// 2. i-1에 안먹고 i-2에 먹기
		int t1 = max(v[i-1]+dp_o[i-3],dp_o[i-2])+v[i];
		dp_o[i] = t1;

		// 이번 턴에 안밟는 경우 : 저번 턴에 밟거나 저저번 턴에 밟거나 중에 무조건 하나
		int t2 = max(dp_o[i-1],dp_o[i-2]);
		dp_x[i] = t2;
	}

	if (n >= 3) {
		cout << dp_o[n-1];
	} else {
		if (n == 1) {
			cout << v[0];
		} else if (n==2) {
			cout << v[0] + v[1];
		}
	}
}


