#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ranges>
// #include<bits/stdc++.h>
#include <limits>
typedef long long ll;
typedef long double ld;
using namespace std;


void rotate(vector<vector<int>>& v,int rowUp, int rowDown, int colLeft, int colRight){
	// 바깥줄 돌리기
	if ((rowDown - rowUp) != (colRight - colLeft)) throw "err not same";
	if (rowUp == rowDown) {
		return;
	}
	int oneLine = rowDown - rowUp;// 한변의 길이

	// 바깥줄돌리기
	// swap 연산 반복
	int y = rowUp;
	int x = colLeft;
	int dx = 0;
	int dy = 1;
	int lastCnt = (oneLine+1)*(oneLine+1) - (oneLine-1)*(oneLine-1) -1;
	for (int cnt =0; cnt<lastCnt; cnt++) {
		int nextY = y+dy;
		int nextX = x+dx;
		swap(v[y][x],v[nextY][nextX]);
		// 방향 전환
		// 1. 아래로 내려가다가 오른쪽으로 전환
		if (dy==1 && dx ==0 && nextY==rowDown) {
			dy = 0;
			dx = 1;
		}
		// 오른쪽으로 가다가 위로 전환
		else if (dy==0 && dx == 1 && nextX == colRight) {
			dy=-1;
			dx=0;
		}
		// 위쪽으로 가다가 왼쪽으로 전환
		else if (dy==-1 && dx==0 && nextY==rowUp) {
			dy=0;
			dx=-1;
		}
		y = nextY;
		x = nextX;
	}
	// 안쪽 사각형이 있는 경우
	rotate(v,rowUp+1,rowDown-1,colLeft+1,colRight-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M,K;
	cin >> N >> M >> K;
	vector<vector<int>> v_org(N,vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j=0; j<M; j++) {
			cin >> v_org[i][j];
		}
	}


	vector<tuple<int,int,int>> rotateType;



	int minAnswer = 2140000000;

	for (int i=0; i<K;i++) {
		int r,c,s;
		cin >> r>> c>> s;
		rotateType.push_back({r,c,s});
	}


	sort(rotateType.begin(),rotateType.end());
	do {
		// cout << "perutaton\n";
		int localMin2 = 2140000000;
		vector<vector<int>> v = v_org;
		for (int t=0; t<K;t++) {
			auto [r,c,s] = rotateType[t];
			rotate(v,r-s-1,r+s-1,c-s-1,c+s-1); // 그리고 r,c는 0부터 시작이므로 -1씩;
		}

		// for (int t1=0;t1<N;t1++) {
		// 	for (int t2=0;t2<M;t2++) {
		// 		cout << v[t1][t2] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// cout << "\n\n";


		for (int row =0; row<N; row++) {
			int acc = 0;
			for (int j =0; j<M; j++) {
				acc+=v[row][j];
			}
			localMin2 = min(localMin2,acc);
		}
		// cout << "경우 : "<< localMin2 << "\n";
		minAnswer = min(localMin2,minAnswer);
	} while (next_permutation(rotateType.begin(),rotateType.end()));

	// for (int t1=0;t1<N;t1++) {
	// 	for (int t2=0;t2<M;t2++) {
	// 		cout << v[t1][t2] << " ";
	// 	}
	// 	cout << "\n";
	// }


	// 실제 정답 출력

	cout << minAnswer;
}