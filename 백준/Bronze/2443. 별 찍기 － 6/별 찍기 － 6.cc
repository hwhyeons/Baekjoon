#include <iostream>
#include <string>
#include <string.h>
#include <sstream>


using namespace std;

int main() {
	int num,space;
	scanf("%d",&num);
	int max = num*2-1;
	for (int i =num; i>=1; i--){
		int star = i*2-1;
		space = (max-star)/2;
		for (int j =0; j<space; j++) {
			printf(" ");
		}
		for (int j =0; j<star; j++){
			printf("*");
		}
		/*
		for (int j =0; j<space; j++) {
			printf(" ");
		}
		*/
		if (i != 1) {
			printf("\n");	
		}
	}
	return 0;
}