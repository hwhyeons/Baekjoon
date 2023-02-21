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
	int cnt = 0;
	while(getline(cin,s,',')) {
		cnt++;
	}
	cout << cnt;

}
	


