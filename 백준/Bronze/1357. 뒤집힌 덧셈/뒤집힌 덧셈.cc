#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;


int rev(int a) {
	string s = to_string(a);
	reverse(s.begin(),s.end());
	return stoi(s);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x,y;
	cin >> x >> y;
	cout << rev(rev(x)+rev(y));
	
}


