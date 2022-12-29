#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			printf(" ");
		}
		for (int j = num - i - 1; j < num; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
