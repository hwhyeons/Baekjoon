#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stack>

using namespace std;


int main() {
	int count;
	scanf("%d",&count);
	stack<string> st;
	for (int i =0;i<count;i++) {
		char chars[26];
		while(1) {
			scanf("%s",&chars);
			char c = getchar();
			string str = chars;
			st.push(str);
			if (c == '\n') break;
		}
		printf("Case #%d: ",i+1);
		while (!st.empty()){
			string str = st.top();
			st.pop();
			printf("%s",str.c_str());
			if (!st.empty()) {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}