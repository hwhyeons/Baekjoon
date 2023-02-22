#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_set<string> s;
	for (size_t i = 0; i < n; i++)
	{
		string a,b;
		cin >> a >> b;
		if (b == "enter") {
			s.insert(a);
		} else {
			s.erase(a);
		}
	}
	vector<string> v(s.begin(),s.end());
	sort(v.begin(),v.end(),[](string a, string b){return a>b;});
	for_each(v.begin(),v.end(),[](auto k){cout << k << "\n";});
	
}
	


