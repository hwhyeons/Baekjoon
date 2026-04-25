// #include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ranges>
#include<deque>
#include <limits>
#include <set>
#include <map>

/*
[] 입력받을 때 1행열부터 시작 주의
[] 이동하거나 그럴때 나머지연산검사
 */

typedef long long ll;
typedef long double ld;
using namespace std;
int N,M,K;


class Ball {
public:
    ll di;
    ll si;
    ll m;
};

int dxs[] = {0,1,1,1,0,-1,-1,-1}; // 인덱스로 작업
int dys[] = {-1,-1,0,1,1,1,0,-1};  // 인덱스로 작업


void moveBall(int startRow, int startCol, Ball& ball,vector<vector<vector<Ball>>>& newV) {
    int dx = dxs[ball.di];
    int dy = dys[ball.di];
    ll speed = ball.si;
    int diffRow = dy*speed;
    int diffCol = dx*speed;
    // 모듈러 연산으로 축약
    int newRow = (startRow%N+diffRow%N+N)%N;
    int newCol = (startCol%N+diffCol%N+N)%N;

    newV[newRow][newCol].push_back({ball.di,ball.si,ball.m});
}

void moveAllFireBall(const vector<vector<vector<Ball>>>& v,vector<vector<vector<Ball>>>& newV) {
    for (int r=0;r<N;r++) {
        for (int c=0;c<N;c++) {
            for (Ball b : v[r][c]) {
                moveBall(r,c,b,newV);
            }
        }
    }
}

void mergeAndSplitFireBall(const vector<vector<vector<Ball>>>& v,vector<vector<vector<Ball>>>& newV, int r, int c) {
    // 두개 미만이면 무반응
    if (v[r][c].size() < 2) {
        for (auto b : v[r][c]) {
            newV[r][c].push_back(b);
        }
        return;
    }
    int curFireBallCnt = v[r][c].size(); // 현재칸파이어볼개수
    ll weightAcc = 0ll; // 질량의합
    for (auto w : v[r][c]) weightAcc += w.m;

    ll speedAcc = 0ll; // 속력의합
    for (auto s : v[r][c]) speedAcc += s.si;

    ll newWeight = weightAcc/5; // 새로운질량
    ll newSpeed = speedAcc/curFireBallCnt; // 새로운속력
    if (newWeight == 0) { // 새 질량이 0인 경우 소멸
        return;
    }
    bool all_odd = true; // 모두 짝수
    bool all_not_odd = true; // 모두 홀수
    for (auto b : v[r][c]) {
        if (b.di%2==0) { // 하나라도 짝수
            all_not_odd = false;
        } else {
            // 하나라도 홀수
            all_odd = false;
        }
    }

    bool all_dir_same_odd = false; // 기존방향이_모두홀수나짝수
    if (all_odd or all_not_odd) all_dir_same_odd = true;

    if (all_dir_same_odd) {
        // 새방향0_2_4_6;
        newV[r][c].push_back({0,newSpeed,newWeight});
        newV[r][c].push_back({2,newSpeed,newWeight});
        newV[r][c].push_back({4,newSpeed,newWeight});
        newV[r][c].push_back({6,newSpeed,newWeight});
    } else {
        // 새방향1_3_5_7;
        newV[r][c].push_back({1,newSpeed,newWeight});
        newV[r][c].push_back({3,newSpeed,newWeight});
        newV[r][c].push_back({5,newSpeed,newWeight});
        newV[r][c].push_back({7,newSpeed,newWeight});
    }

}

ll getAllAccWeight(const vector<vector<vector<Ball>>>& v) {
    ll acc = 0ll;
    for (int r=0;r<N;r++) {
        for (int c=0;c<N;c++) {
            for (Ball b : v[r][c]) {
                acc+=b.m;
            }
        }
    }
    return acc;
}

void mergeAndSplitFireBallAll(const vector<vector<vector<Ball>>>& v,vector<vector<vector<Ball>>>& newV) {
    for (int r=0;r<N;r++) {
        for (int c=0;c<N;c++) {
            mergeAndSplitFireBall(v,newV,r,c);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    vector<vector<vector<Ball>>> v(N,vector<vector<Ball>>(N,vector<Ball>()));
    for (int i=0;i<M;i++) {
        ll a,b,mi,si,di;
        cin >> a >> b >> mi >> si >> di;
        int row = a-1;
        int col = b-1;
        v[row][col].push_back({di,si,mi});
    }

    for (int cnt=0;cnt<K;cnt++) {
        vector<vector<vector<Ball>>> newV1(N,vector<vector<Ball>>(N,vector<Ball>()));
        moveAllFireBall(v,newV1); // 파이어볼 이동
        vector<vector<vector<Ball>>> newV2(N,vector<vector<Ball>>(N,vector<Ball>()));
        mergeAndSplitFireBallAll(newV1,newV2);
        // swap으로 개선 : 기존벡터=새로운벡터로처리
        swap(v,newV2);
    }
    cout << getAllAccWeight(v);
}