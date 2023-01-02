#include <iostream>
#include <string>
#include <string.h>
#include <sstream>


using namespace std;

int main() {
	int h,m;
	scanf("%d %d",&h,&m);
	
	int num = h*60 + m;
	num -= 45;
	if (num < 0) {
		num += 24*60;
	}
	
	h = num/60;
	m = (num%60);
	
	printf("%d %d",h,m);
	return 0;
}