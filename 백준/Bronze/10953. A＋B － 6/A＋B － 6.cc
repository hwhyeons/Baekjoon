#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n;
	for (int i=0;i<n;i++) {
		cin >> s;
		int a = stoi(s.substr(0,1));
		int b = stoi(s.substr(2,1));
		cout << a+b << "\n";
	}
	
}


