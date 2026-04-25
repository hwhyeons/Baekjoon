#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

int N,K;
class Node {
public:
    int num; // 노드번호
    int dir;
};


vector<vector<int>> v;
vector<vector<deque<Node>>> nodes; // 좌표에 있는 노드
vector<pair<int,int>> nodePos; // N+1개

int dy[] = {0,0,0,-1,1};
int dx[] = {0,1,-1,0,0};

const int WHITE = 0;
const int BLUE = 2;
const int RED = 1;


int getNodeDir(int y, int x, int nodeNum) {
    for (Node node : nodes[y][x]) {
        if (node.num == nodeNum) {
            return node.dir;
        }
    }
    throw "cannot find";
}

int reverseDir(int dir) {
    if (dir==1) return 2;
    if (dir==2) return 1;
    if (dir==3) return 4;
    if (dir==4) return 3;
    throw "not here";
}

// 파랑 2
bool moveNode(const int nodeNum) {
    int gotoCount = 0;
    label:
    if (gotoCount >= 1000) throw "Err";
    auto [curY,curX] = nodePos[nodeNum];
    int curDir = getNodeDir(curY,curX,nodeNum);
    // 다음 좌표와 방향 구하기
    int nextY = curY+dy[curDir];
    int nextX = curX+dx[curDir];
    int nextColor;
    int nextDir = curDir;
    if (nextY <0 || nextX <0 || nextY>=N || nextX>=N) { // nextY,nextX초과시 파랑처리;
        nextColor =  BLUE;
        if (nextY <0) nextY = 0;
        if (nextX <0) nextX = 0;
        if (nextY >=N) nextY=N-1;
        if (nextX >=N) nextX=N-1;
    } else {
        nextColor = v[nextY][nextX];
    }

    if (nextColor == BLUE) { // 파랑 or 벽막힌 경우
        nextDir = reverseDir(curDir);
    }

    // 이동시 : nodePos[nodeNum]변경 -> nodes[nextY][nextX]추가 -> nodes[curY][curX] 삭제
    if (nextColor == RED || nextColor == WHITE) {
        bool find = false;
        int index = 0; // 삭제할 시작 인덱스
        // 이동시 : nodePos[nodeNum]변경 -> nodes[nextY][nextX]추가 -> nodes[curY][curX] 삭제
        if (nextColor == RED) {
            for (int i=((int)nodes[curY][curX].size()-1); i>=0; i--) {
                // 역순으로 옮기면
                nodePos[nodes[curY][curX][i].num] = {nextY,nextX}; // 좌표 변경
                nodes[nextY][nextX].push_back(nodes[curY][curX][i]); // 깊은복사
                if (nodes[curY][curX][i].num == nodeNum) {
                    find = true;
                    index = i;
                    break;
                }
            }
        } else {
            // 흰색
            for (int i=0;i<nodes[curY][curX].size();i++) {
                // 정방향 옮기기
                if (nodes[curY][curX][i].num == nodeNum || find) {
                    nodePos[nodes[curY][curX][i].num] = {nextY,nextX}; // 좌표 변경
                    nodes[nextY][nextX].push_back(nodes[curY][curX][i]); // 깊은복사
                    if (!find) {
                        find = true;
                        index = i;
                    }
                }
            }
        }

        if (!find) throw "err";
        // 현재에서 index부터 end까지 삭제
        nodes[curY][curX].erase(nodes[curY][curX].begin()+index,nodes[curY][curX].end()); // 삭제 한번에
    } else if (nextColor == BLUE) {
        // 일단 방향 강제로 변경후에 다시 goto
        if (gotoCount==0) {
            for (int i=0;i<nodes[curY][curX].size();i++) {
                if (nodes[curY][curX][i].num == nodeNum) {
                    nodes[curY][curX][i].dir = nextDir;
                    break;
                }
            }
            gotoCount++;
            goto label;
        }
        // 한번이라도 이동한경우 끝

        // 파랑색은 좌표가 뒤집혀서 이동
        // int nextY2 = nextY+dy[nextDir];
        // int nextX2 = nextX+dx[nextDir];
        // 또 파란색이나 벽이 아닌경우 -> 똑같은 로직으로 이동
        // if (!(nextY2<0 || nextX2 <0 || nextY2>=N || nextX2>=N)  && v[nextY2][nextX2] != BLUE) {
        //     // 노드 찾아서 일단 방향 변경
        //     bool change = false;
        //     for (int i=0;i<nodes[curY][curX].size();i++) {
        //         if (nodes[curY][curX][i].num == nodeNum) {
        //             nodes[curY][curX][i].dir = nextDir;
        //             change = true;
        //             break;
        //         }
        //     }
        //     if (!change) throw "err";
            // gotoCount++;
            // goto label;
        //}
    } else {
        throw "Err";
    }
    if (nodes[nextY][nextX].size()>=4) {
        return true;
    } else {
        return false;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    v.assign(N,vector<int>(N));
    nodes.assign(N,vector<deque<Node>>(N));
    nodePos.assign(K+1,{-1,-1});
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> v[i][j];
        }
    }
    for (int i=1;i<=K;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        int row = a-1;
        int col = b-1;
        int dir = c;
        nodes[row][col].push_back({i,dir}); // 노드 1번부터 시작
        nodePos[i] = {row,col};
    }
    for (int turn=1;turn<=1000;turn++) {
        // cout << "turn : " << turn << "\n";
        // 1번말부터 이동
        for (int moveNum=1;moveNum<=K;moveNum++) {
            if (moveNode(moveNum)) {
                cout << turn;
                exit(0);
            }
        }
    }
    cout << -1;

    return 0;
}