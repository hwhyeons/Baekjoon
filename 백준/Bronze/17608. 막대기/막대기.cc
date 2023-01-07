#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stack>

using namespace std;


int main() {
	int count;
	stack<int> st;
	scanf("%d",&count);
	int see = 0;
	int cur;
	for (int i =0; i<count; i++) {
		scanf("%d",&cur);
		st.push(cur);
	}

	int max = -1;
	for (int i = 0; i < count; i++) {
		int top = st.top();
		st.pop();
		if (max < top) {
			see+=1;
			max = top;
		}
	}
	printf("%d",see);
	return 0;
}