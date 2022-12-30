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
	for (int i = num; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
