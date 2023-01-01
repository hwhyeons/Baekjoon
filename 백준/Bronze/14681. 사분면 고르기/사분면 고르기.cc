#include <iostream>
#include <string>
#include <string.h>
#include <sstream>


using namespace std;

int main() {
	int x,y,ans;
	scanf("%d\n%d",&x,&y);
	if (x >0) {
		if (y >0) {
			ans = 1;
		} else {
			ans = 4;
		}
	} else { // x는 음수 
		if (y > 0) {
			ans = 2;
		} else {
			ans = 3;
		}
	}
	printf("%d",ans);
	return 0;
}