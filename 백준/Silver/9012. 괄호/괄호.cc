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
	for (int i =0;i<count;i++){
		char chr[50];
		string answer = "YES";
		scanf("%s",chr);
		stack<char> st;
		for (int j =0; j<50; j++) {
			if (chr[j] == '\0') break;
			if (chr[j] == '('){
				st.push('(');
			} else {
				if (st.empty()) {
					answer = "NO";
					break;
				} else {
					st.pop();
				}
			}
		}
		if (!st.empty()) answer = "NO";
		printf("%s\n",answer.c_str());
	}
	return 0;
}