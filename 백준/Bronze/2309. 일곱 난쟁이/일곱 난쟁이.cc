#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <numeric>

using namespace std;

bool finish = false;

void go(int ar[], int out[],int depth, int idx) {
	if (finish || idx >= 9) return;
	out[depth] = ar[idx];
	if (depth == 6) {
		int sum = accumulate(out,out+7,0);
		if (sum != 100) return;
		for (int i=0;i<7;i++) {
			printf("%d\n",out[i]);	
		}
		finish = true;
		return;
	}
	
	for (int i=idx+1;i<9;i++) {
		go(ar,out,depth+1,i);
	}
}

int main() {
	int arr[9];
	for (int i=0;i<9;i++) {
		scanf("%d",&arr[i]);	
	}
	
	sort(arr,arr+9);
	int out[7];
	for (int i =0;i<9;i++) {
		go(arr,out,0,i);
	}
	return 0;
}



//%d


