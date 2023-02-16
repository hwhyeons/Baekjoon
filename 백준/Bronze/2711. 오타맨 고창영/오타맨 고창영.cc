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
	int n,idx;
	string tmp;
	cin >> n;
	for (int i =0; i<n; i++) {
		cin >> idx >> tmp;
		tmp.erase(tmp.begin()+idx-1);
		cout << tmp << "\n";
	}

}


