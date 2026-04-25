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
int N;

// int maxAns;
int curTurn = 0;
int maxAnswer = 0;
void moveOne(vector<int>& rue, int& point,int& out) {
    if (rue[3] != -1) point++;
    rue[3] = rue[2];
    rue[2] = rue[1];
    rue[1] = rue[0];
    rue[0] = -1;
}

int playGame(vector<vector<int>>& rounds, vector<int>& order, int rnd) {
    int point = 0;
    int out = 0;
    vector<int> rue = {-1,-1,-1,-1}; // 타자 -> 1루 -> 2루 -> 3루
    while (out < 3) {
        if (curTurn == 9) curTurn =0;
        int curPlayerIndex = order[curTurn];
        int curPlayerPointType = rounds[rnd][curPlayerIndex];
        rue[0] = curPlayerIndex;
        if (curPlayerPointType == 0) { // 아웃
            out++;
            rue[0] = -1;
        } else if (curPlayerPointType == 1) {
            moveOne(rue,point,out);
        } else if (curPlayerPointType == 2) { // 2루타
            moveOne(rue,point,out);
            moveOne(rue,point,out);
        } else if (curPlayerPointType == 3) {
            moveOne(rue,point,out);
            moveOne(rue,point,out);
            moveOne(rue,point,out);
        } else if (curPlayerPointType == 4) {
            moveOne(rue,point,out);
            moveOne(rue,point,out);
            moveOne(rue,point,out);
            moveOne(rue,point,out);
        } else {
            throw "err";
        }
        curTurn++;
    }
    return point;

}

void dfs(vector<vector<int>>& rounds, vector<int>& order,vector<bool>& visit, int depth) {
    // 다 채워지면 시작
    if (depth == 9) {
        curTurn = 0;
        int acc = 0;
        for (int rnd =0; rnd<N; rnd++) {
            int localPoint = playGame(rounds,order,rnd);
            acc+= localPoint;
        }
        maxAnswer = max(acc,maxAnswer);
        return;
    }
    // 1번타자는 4번 고정
    if (depth == 3) {
        order[depth] = 0;
        visit[0] = true;
        dfs(rounds,order,visit,depth+1);
        visit[0] = false;
    } else {
        for (int idx=1; idx<9; idx++) {
            if (visit[idx]) continue;
            // if (idx==0) continue;
            visit[idx] = true;
            order[depth] = idx;
            dfs(rounds,order,visit,depth+1);
            visit[idx] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<vector<int>> rounds(N, vector<int>(9)); // 라운드별 값
    for (int i=0; i<N; i++) {
        for (int j=0; j<9; j++) {
            cin >> rounds[i][j];
        }
    }
    vector<int> order(9,-1);
    vector<bool> visit(9);
    dfs(rounds,order,visit,0);
    cout << maxAnswer;

}