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


vector<vector<int>> v(10,vector<int>(10));
vector<int> leftCnt = {0,5,5,5,5,5};
vector<pair<int,int>> oneYX; // 시작값이 1인 (y,x)
int oneCnt =0; // 남은 1카운트

int answer = 2100000000;

bool canUse(int paperSize, int y, int x) {
    if (paperSize <= 0 || paperSize >5) throw "Err";

    // 종이 개수가 부족한 경우
    if (leftCnt[paperSize] == 0) return false;

    for (int ny=y;ny<y+paperSize; ny++) {
        for (int nx=x;nx<x+paperSize; nx++) {
            //    좌표가 벗어나면false;
            if (ny >= 10 || nx >= 10) return false;
            // 좌표내에전부1이아니면리턴false;
            if (v[ny][nx] != 1) return false;
        }
    }
    return true;
}

bool usePaper(int paperSize, int y, int x, bool fill_tf) {
    if (fill_tf && !canUse(paperSize,y,x)) return false;
    if (fill_tf) {
        leftCnt[paperSize] -=1;
    } else {
        leftCnt[paperSize] +=1;
    }
    for (int i = y; i<y+paperSize; i++) {
        for (int j=x; j<x+paperSize; j++) {
            if (i>=10 || j>=10) throw "err";
            if (fill_tf) {
                v[i][j] = 0; // 사용
                oneCnt-=1;
                if (oneCnt < 0 ) throw "err";
            } else {
                v[i][j] = 1; // 복구
                oneCnt +=1;
            }
        }
    }
    return true;
}

void dfs(int yxIdx, int localAnswer) {
    // if (정답조건oneCnt사용);
    // cout << "yxIdx " << yxIdx << "\n";
    if (oneCnt == 0) {
        answer = min(answer,localAnswer);
        return;
    }
    if (localAnswer >= answer) return;
    if (yxIdx >= oneYX.size()) {
        return; // 끝을 넘은 경우
    }

    auto [y,x] = oneYX[yxIdx];
    // 이미 채워진 경우 다음 인덱스로
    if (v[y][x] == 0) {
        dfs(yxIdx+1,localAnswer);
        return;
    }
    // 1번 사이즈부터 5번 사이즈까지
    for (int s=5; s>=1; s--) {
        bool use = usePaper(s,y,x,true);
        if (!use) continue;
        dfs(yxIdx+1,localAnswer+1); // use가 true면 종이 하나 사용한 것
        bool disuse = usePaper(s,y,x,false);
        if (!disuse) {
            throw "err";
        }
    }
    // dfs(yxIdx+1,localAnswer);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i =0;i<10;i++) {
        for (int j =0;j<10;j++) {
            cin >> v[i][j];
            if (v[i][j] == 1) {
                oneYX.push_back({i,j});
                oneCnt+=1;
            }
        }
    }

    dfs(0,0);
    if (answer == 2100000000) {
        cout << "-1";
    } else {
        cout << answer;
    }

    // for (int i =0;i<10;i++) {
    //     for (int j =0;j<10;j++) {
    //         if (v[i][j] != 0) continue;
    //         dfs(i,j);
    //     }
    // }

}