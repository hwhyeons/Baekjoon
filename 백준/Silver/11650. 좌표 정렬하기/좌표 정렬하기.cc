#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Pair {
public:
	int x,y;
};

bool compare(const Pair& p1, const Pair& p2) {
	if (p1.x == p2.x) {
		if (p1.y < p2.y) {
			return true;
		} else {
			return false;
		}
	} else {
		if (p1.x < p2.x) {
			return true;
		} else {
			return false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b;
	cin >> n;
	vector<Pair> v;
	for(int i =0; i<n; i++) {
		cin >> a >> b;
		Pair p;
		p.x = a;
		p.y = b;
		v.push_back(p);
	}
	sort(v.begin(),v.end(),compare);
	for_each(v.begin(),v.end(),[](auto p){cout << p.x << " " << p.y << "\n";});
}
	


