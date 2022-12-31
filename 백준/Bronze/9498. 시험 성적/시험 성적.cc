#include <iostream>
#include <string>
#include <string.h>
#include <sstream>


using namespace std;

int main() {
	int num;
	scanf("%d",&num);
	char g;
	if (num >= 90) {
		g = 'A';
	} else if (num >= 80){
		g = 'B';
	} else if (num >= 70){
		g = 'C';
	} else if (num >= 60){
		g = 'D';
	} else {
		g = 'F';
	}
	printf("%c",g);
	return 0;
}