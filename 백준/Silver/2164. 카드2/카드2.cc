#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <list>

using namespace std;


int main() {
	list<int> arr;
	int count;
	scanf("%d",&count);
	for (int i =0;i<count;i++){
		arr.push_back(i+1);
	}
	for (int i =1;i<count;i++){ // 버리는 횟수 
		arr.pop_front(); // 하나 삭제 
		int front = arr.front(); // 뒤로 보낼 것
		arr.pop_front();
		arr.push_back(front); 
	}
	int answer = arr.front();
	printf("%d",answer);
	return 0;
}