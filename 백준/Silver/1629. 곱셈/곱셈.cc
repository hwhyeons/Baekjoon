#include <iostream>
#include <string>
#include <string.h>
#include <sstream>

typedef long long ll;

using namespace std;

ll go(ll a, ll n, ll c);

ll go(ll a, ll n, ll c) {
	ll rt;
	if (n == 1) {
		return a%c;
	} else if (n==0) {
		return 1;
	}
	rt = go(a,n/2,c)%c;
	if (n%2 ==0) { // 짝 
		return rt*rt%c;
	} else {
		return rt*rt%c*a%c;
	}
}

int main() {
	ll A,B,C;
	cin >> A >> B >> C;
	// scanf("%d %d %d",&A,&B,&C);
	ll answer = go(A,B,C);
	cout << answer;
	// printf("%d",answer);
	return 0;
}