#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int f(int a, int b) {
	if (b == 0) return a;
	return f(b,a%b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin >> a >> b;
	int min = f(a,b);
	int max = min*(a/min)*(b/min);
	cout << min << "\n" << max;
}

