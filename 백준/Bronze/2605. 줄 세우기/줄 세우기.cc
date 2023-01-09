#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int tmp;
	int size = 0;
	vector<int> arr;
	vector<int>::reverse_iterator it;
	for (int i = 1;i <= n;i++) {
		scanf("%d", &tmp);
		it = arr.rbegin()+tmp;
		arr.insert(it.base(), i);
		printf("");
	}

	// 출력
	vector<int>::iterator it1 = arr.begin();
	while (it1 != arr.end()) {
		printf("%d", *it1);
		it1++;
		if (it1 == arr.end()) break;
		else printf(" ");
	}
	
	return 0;
}
