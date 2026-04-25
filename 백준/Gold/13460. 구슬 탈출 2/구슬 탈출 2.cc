#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
typedef long double ld;
using namespace std;


int N,M;

const int LEFT = 0;
const int RIGHT = 1;
const int UP = 2;
const int DOWN = 3;



int dys[] = {0,0,-1,1};
int dxs[] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    vector<vector<char>> v(N,vector<char>(M));
    int startBlueY,startBlueX,startRedY,startRedX,zeroY,zeroX;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> v[i][j];
            if (v[i][j] == 'B') {
                startBlueY = i;
                startBlueX = j;
            } else if (v[i][j] == 'R') {
                startRedY = i;
                startRedX = j;
            } else if (v[i][j] == 'O') {
                zeroY = i;
                zeroX = j;
            }
        }
    }
    int answer = -1;

    // {blueY,blueX,redY,redX,turn누적}
    queue<tuple<int,int,int,int,int>> q;
    q.push({startBlueY,startBlueX,startRedY,startRedX,0}); // turn은 0부터 시작
    while (!q.empty()) {
        auto [blueY,blueX,redY,redX,curTurn] = q.front(); q.pop();
        if (curTurn >= 11) break;
        if (blueY == zeroY && blueX == zeroX) continue; // 파란공이 빠진 경우는 불가능
        if (redY == zeroY && redX == zeroX) {
            answer = curTurn;
            break; // 바로 break해야 최소 정답으로 출력
        }
        // cout << blueY << " " << blueX << " " << redY << " " << redX << "\n";

        // 각각 독립적으로 이동. 파랑이 부터
        // 이 방식의 핵심은 "누가 먼저 출발하든 영향을 안받고 독립적으로 이동시킨다음에 나중에 처리"
        for (int dir=0;dir<4;dir++) {
            int blueMoveCount = 0;
            int redMoveCount = 0;
            int newBlueY = blueY;
            int newBlueX = blueX;
            int newRedY = redY;
            int newRedX = redX;
            while (1) {
                int ny = newBlueY + dys[dir];
                int nx = newBlueX + dxs[dir];
                if (ny==0 || nx==0 || ny==N-1 || nx==M-1) break;
                if (v[ny][nx] == '#') break;
                newBlueY = ny;
                newBlueX = nx;
                blueMoveCount++;
                if (v[ny][nx] == 'O') break;
            }

            while (1) {
                int ny = newRedY + dys[dir];
                int nx = newRedX + dxs[dir];
                if (ny==0 || nx==0 || ny==N-1 || nx==M-1) break;
                if (v[ny][nx] == '#') break;
                newRedY = ny;
                newRedX = nx;
                redMoveCount++;
                if (v[ny][nx] == 'O') break;
            }

            if (blueMoveCount == 0 && redMoveCount == 0) continue;

            // 만약에 두 좌표가 겹치는 경우에 대해 처리
            if (newBlueY == newRedY && newRedX == newBlueX) {
                // 1. 겹치는 좌표가 구멍이 있는 위치인 경우 => 이 방향으로 기울이는건 정답이 아예 될 수 없음
                if (newBlueY == zeroY && newBlueX == zeroX) {
                    continue;
                } else {
                    // 2. 겹치는 좌표가 구멍이 없는 위치인 경우 => 이동거리가 높은애를 하나 물리면 됨
                    // 이동거리가 높다는건 그만큼 특정 방향으로 더 많이 움직였다는거고
                    // 만약 왼쪽으로 기울이는 상황이라면, 이동거리가 많은 애가 더 오른쪽에 있었다는 것임
                    if (blueMoveCount > redMoveCount) {
                        newBlueY -= dys[dir];
                        newBlueX -= dxs[dir];
                    } else if (redMoveCount > blueMoveCount) {
                        newRedY -= dys[dir];
                        newRedX -= dxs[dir];
                    } else {
                        throw "이게 같다면 출발할 때부터 동일한 좌표라는 얘기라서 불가능";
                    }
                }
            }

            // 여기까지 왔으면 정답이 가능한 케이스라는 것
            q.push({newBlueY,newBlueX,newRedY,newRedX,curTurn+1});
        }
    }

    cout << answer;

}