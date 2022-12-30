#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;
int main()
{
	int a;
	int b;
	scanf("%d", &a);
	scanf("%d", &b);
	if (a < b) {
		printf("<");
	} else if (a == b) {
		printf("==");
	} else {
		printf(">");
	}
	return 0;
}
