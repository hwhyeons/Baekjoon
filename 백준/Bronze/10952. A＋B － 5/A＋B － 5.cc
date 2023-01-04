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
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) break;
		printf("%d\n",a + b);
	}
	
	return 0;
}
