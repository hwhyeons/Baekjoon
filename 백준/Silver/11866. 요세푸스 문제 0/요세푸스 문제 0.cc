#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <deque>
#include <set>


using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	vector<int> v;
	for (int i =0; i<n;i++){
		v.push_back(i+1);
	}

	int curIdx = 0;
	cout << "<";
	while (true) {
		int removeIdx = (curIdx+k-1)%(v.size());
		cout << v[removeIdx];
		v.erase(v.begin()+removeIdx);
		curIdx = removeIdx;
		if (v.size() == 0) {
			cout << ">";
			break;
		} else {
			cout << ", ";
		}
	}
}


