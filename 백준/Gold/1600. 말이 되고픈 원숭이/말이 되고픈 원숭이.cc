#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
typedef long double ld;
using namespace std;

// 상하좌우 + 특수 이동
int dys[] = {1,-1,0,0,-2,-2,2,2,1,1,-1,-1};
int dxs[] = {0,0,1,-1,1,-1,1,-1,-2,2,-2,2};

struct Horse {
    int y;
    int x;
    int specialUseCount; // 특수 동작 수만
    int moveCount; // 이동 횟수 (정답용)
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    cin >> K;
    int W,H;
    cin >> W >> H;
    vector<vector<int>> v(H,vector<int>(W));
    for (int i=0;i<H;i++) {
        for (int j=0;j<W;j++) {
            cin >> v.at(i).at(j);
        }
    }

    // y->x->특수 스킬 사용 횟수
    vector<vector<vector<bool>>> visited(H,vector<vector<bool>>(W,vector<bool>(K+1)));
    queue<Horse> q;
    q.push({0,0,0,0});
    visited[0][0][0] = true;
    int answer = -1; // min() 쓰지말기!!
    while (!q.empty()) {
        Horse h = q.front(); q.pop();
        // 도착지 도착
        if (h.y == H-1 && h.x == W-1) {
            answer = h.moveCount;
            break;
        }

        // 이웃으로 이동 : 일반 동작
        for (int idx=0;idx<12;idx++) {
            bool isSpecial = idx >= 4 ? true : false; // idx4부터는 특수동작
            int ny = h.y + dys[idx];
            int nx = h.x + dxs[idx];
            // 1. 범위를 넘어선 경우
            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            // 2. 장애물을 만난 경우
            if (v[ny][nx]==1) continue;
            // 3. 지금 이동할 방향이 특수방향이면서 이미 방문한 경우
            if (isSpecial && visited[ny][nx][h.specialUseCount+1]) continue;
            // 4. 지금 이동할 방향이 일반 방향이면서 이미 방문한 경우
            if (!isSpecial && visited[ny][nx][h.specialUseCount]) continue;
            // 5. 지금 이동할 방향이 특수 방향인데 방향 횟수 넘어간 경우
            if (isSpecial && h.specialUseCount>=K) {
                continue;
            } else if (isSpecial && h.specialUseCount < K) { // 특수 방향인데 사용가능
                visited[ny][nx][h.specialUseCount+1] = true;
                q.push({ny,nx,h.specialUseCount+1,h.moveCount+1});
                continue;
            }
            // 6. 일반 방향
            visited[ny][nx][h.specialUseCount] = true;
            q.push({ny,nx,h.specialUseCount,h.moveCount+1});
            continue;
        }
    }
    cout << answer; // 없으면 자동으로 -1출력


}