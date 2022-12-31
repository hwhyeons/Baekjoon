#include <iostream>
#include <string>
#include <string.h>
#include <sstream>


using namespace std;

int main() {
	int year;
	int ans = 0;
	scanf("%d",&year);
	if (year%400 == 0) {
		ans = 1;
	} else if (year%4 ==0 && year%100 != 0) {
		ans = 1;
	}
	
	printf("%d",ans);
	return 0;
}