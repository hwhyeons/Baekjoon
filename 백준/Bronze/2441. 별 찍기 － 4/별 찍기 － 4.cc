#include <iostream>
#include <string>
#include <string.h>
#include <sstream>


using namespace std;

int main() {
	int num;
	scanf("%d",&num);
	for (int i =0; i < num; i++) {
		for (int j =0; j<i; j++) {
			printf(" ");
		}
		for (int j =i; j<num; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}