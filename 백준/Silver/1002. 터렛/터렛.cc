#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	int t_count; // 테스트 케이스 갯 
	scanf("%d",&t_count);
	int inform[6];
	// 테스트 케이스 
	for (int t =0;t<t_count;t++) {
		int ans;
		for(int i=0;i<6;i++) {
			scanf("%d",&inform[i]); // x1,y1,r1 ...
		}
		int x1 = inform[0];
		int y1 = inform[1];
		int r1 = inform[2];
		int x2 = inform[3];
		int y2 = inform[4];
		int r2 = inform[5];
		int r1r2 = r1+r2;
		int cond1 = (r1-r2)*(r1-r2);
		int cond2 = (r1+r2)*(r1+r2);
		int d2 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
		
		if (d2 == 0) {
			if (cond1 == 0) {
				ans = -1;
			} else {
				ans = 0;
			}
		} else if (d2 == cond1 || d2 == cond2) {
			ans = 1;
		} else if (cond1 < d2 && d2 < cond2) {
			ans = 2;
		} else {
			ans = 0;
		}
		printf("%d\n",ans);
	}
	return 0;
}

//%d


