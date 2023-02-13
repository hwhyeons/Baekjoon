#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>


using namespace std;

vector<int> v(9);
vector<int> idx(9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 9; i++){
		cin >> v[i];
	}
	for (int i = 0; i<7; i++)
	{
		idx[i] = 1;
	}

	sort(v.begin(),v.end());
	do
	{
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			sum += idx[i] == 1 ? v[i] : 0;
		}
		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (idx[i] == 1) {
					cout << v[i] << "\n";
				}
			}
			return 0;
		}
	} while (prev_permutation(idx.begin(),idx.end()));
	
	
}


