#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c;
	int mx = 15,my=28,mz=19;
	cin >> a >> b >> c;
	int cur = 1;
	int x=1,y=1,z=1;
	while (!(x==a && y==b && z==c)) {
		x = (++x)%(mx+1);
		y = (++y)%(my+1);
		z = (++z)%(mz+1);
		if (x == 0) x++;
		if (y == 0) y++;
		if (z == 0) z++;
		cur++;
	}
	cout << cur;


}


