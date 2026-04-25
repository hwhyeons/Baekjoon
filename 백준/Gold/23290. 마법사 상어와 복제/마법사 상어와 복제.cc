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

typedef long long ll;
typedef long double ld;
using namespace std;


int sharkY;
int sharkX;

class Fish {
public:
    int dir;

};

typedef int Row;
typedef int Col;

int dys[] = {0,0,-1,-1,-1,0,1,1,1};
int dxs[] = {0,-1,-1,0,1,1,1,0,-1};

// 모든 물고기 1칸 이동
void moveFishAll1(const vector<vector<vector<Fish>>>& v,vector<vector<vector<Fish>>>& newVec,const vector<vector<deque<int>>>& smells) {
    for (int r=0;r<4;r++) {
        for (int c=0;c<4;c++) {
            for (Fish f : v[r][c]) {
                // const int startDir = f.dir;
                int curDir = f.dir;
                // 실패할 경우를 대비해 그대로 위치해있기
                int finalNextDir = curDir;
                int finalNextY = r;
                int finalNextX = c;
                for (int turnTime=0;turnTime<=8;turnTime++) {
                    int ny = r+dys[curDir];
                    int nx = c+dxs[curDir];
                    if (ny<0 || nx<0 || ny>=4 || nx>=4) {
                        ;
                    } else if (ny==sharkY && nx==sharkX) {
                        ;
                    } else if (!smells[ny][nx].empty()) { // 물고기 냄새 존재
                        ;
                    } else {
                        // 가능한 경우
                        finalNextDir = curDir;
                        finalNextY = ny;
                        finalNextX = nx;
                        break;
                    }

                    // 나머지는 불가능
                    // 회전방향은음수가 맞음
                    curDir--;
                    if (curDir ==0) curDir=8;
                }

                int nextDir = finalNextDir;// 상어가 있는 칸, 물고기의 냄새가 있는 칸, 격자의 범위를 벗어나는 칸으로는 이동할 수 없다;
                int newRow = finalNextY;
                int newCol = finalNextX;
                newVec[newRow][newCol].push_back({nextDir});

            }
        }
    }

}


typedef int RemoveFishCount;
typedef int DirTriple;

// 상어가 3칸 이
void sharkMove3(vector<vector<vector<Fish>>>& v,vector<vector<deque<int>>> &smells, const int timeStamp) {
    // 상어는 상하좌우만가능
    // 방향 후보군 리스트
    vector<pair<RemoveFishCount,DirTriple>> dirs;
    for (int dir1=1;dir1<=4;dir1++) {
        for (int dir2=1;dir2<=4;dir2++) {
            for (int dir3=1;dir3<=4;dir3++) {
                // 주의 : 상은 1, 좌는 2, 하는 3, 우는 4
                int ny = sharkY;
                int nx = sharkX;
                vector<int> dirList = {dir1,dir2,dir3};
                bool ok = true;
                int removeFishCount = 0; // 지울 수 있는 생선 수
                vector<vector<bool>> visited(4,vector<bool>(4));
                for (int sharkDir : dirList) {
                    if (sharkDir==1) {
                        ny--;
                    } else if (sharkDir==2) {
                        nx--;
                    } else if (sharkDir==3) {
                        ny++;
                    } else if (sharkDir==4) {
                        nx++;
                    } else {
                        throw "Err";
                    }
                    // 가는중에 막히는 것도 체크해야함
                    if (ny<0 || nx<0 || ny>=4 || nx>=4) {
                        ok = false;
                        break;
                    }
                    // 생선이 있는 경우
                    if (!v[ny][nx].empty() && !visited[ny][nx]) {
                        removeFishCount += v[ny][nx].size();
                    }
                    visited[ny][nx] = true;
                }
                if (!ok) continue; // 중간에 한번이라도 막힌 경우

                int finalDirTriple = 100*dir1 + 10*dir2 + 1*dir3;

                dirs.push_back({-removeFishCount,finalDirTriple});
            }
        }
    }

    // 정렬하기
    sort(dirs.begin(),dirs.end());
    if (dirs.size()==0) throw "impossible";

    int bestRemoveCnt = -dirs[0].first;
    int bestDirTriple = dirs[0].second;
    int dir1Best = bestDirTriple/100;
    int dir2Best = (bestDirTriple%100)/10;
    int dir3Best = (bestDirTriple%100%10);
    // 최종이동방향이 결정됨
    // 연속해서 이동하는 중에 상어가 물고기가 있는 같은 칸으로 이동하게 된다면, 그 칸에 있는 모든 물고기는 격자에서 제외;
    vector<int> dirr = {dir1Best,dir2Best,dir3Best}; // 3개
    int curY = sharkY;
    int curX = sharkX;
    for (int d : dirr) {
        if (d==1) {
            curY--;
        } else if (d==2) {
            curX--;
        } else if (d==3) {
            curY++;
        } else if (d==4) {
            curX++;
        } else {
            throw "Err";
        }

        // 물고기냄새남기기
        // 냄새 여러개 남길 수는 있어도.. 사라지는 시점은 동일하니 굳이 신경안써도 될듯
        if (!v[curY][curX].empty()) {
            smells[curY][curX].push_back(timeStamp);
            // 실제로물고기지우기
            v[curY][curX].clear();
        }



    }


    // 실제상어좌표변경
    sharkY = curY;
    sharkX = curX;



}

void copyFish(const vector<vector<vector<Fish>>>& v, vector<tuple<Fish,Row,Col>>& copyFishVec) {
    for (int r=0;r<4;r++) {
        for (int c=0;c<4;c++) {
            for (Fish f : v[r][c]) {
                copyFishVec.push_back({f,r,c});
            }
        }
    }
}

void removeSmell(vector<vector<deque<int>>>& smells, int timeStamp) {
    // 주의_두번전꺼지우는거임;
    int removeStamp = timeStamp-2; // 현재 시간이 3이면
    for (int r=0;r<4;r++) {
        for (int c=0;c<4;c++) {
            auto& d = smells[r][c];
            while (!d.empty()) {
                if (d.front()==removeStamp) { // 예를들어 3이면 1번 시간 삭제
                    d.pop_front();
                    continue;
                }
                // 지울게 없으면
                break;
            }
        }
    }
}

void printVec(const vector<vector<vector<Fish>>>& v) {
    return;
    cout << "\n";
    for (int r=0;r<4;r++) {
        for (int c=0;c<4;c++) {
            cout << v[r][c].size() << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll M,S;
    cin >> M >> S;
    vector<vector<vector<Fish>>> v(4,vector<vector<Fish>>(4,vector<Fish>()));
    for (int i=0;i<M;i++) {
        int fx,fy,d;
        cin >> fx >> fy >> d;
        fx--;
        fy--;
        v[fx][fy].push_back({d});
    }
    cin >> sharkY >> sharkX;
    sharkX--;
    sharkY--;

    vector<vector<deque<int>>> smells(4,vector<deque<int>>(4,deque<int>())); // 냄새타임스탬프

    for (int turn=1;turn<=S;turn++) {
        // 복제마법
        printVec(v);
        vector<tuple<Fish,Row,Col>> copyFishVec;
        copyFish(v,copyFishVec);
        vector<vector<vector<Fish>>> newVec(4,vector<vector<Fish>>(4,vector<Fish>()));
        moveFishAll1(v,newVec,smells); // 모든 물고기가 1칸 이동
        printVec(newVec);
        sharkMove3(newVec,smells,turn); // 상어가 3칸 이동
        printVec(newVec);

        removeSmell(smells,turn); // 물고기 냄새 제거
        // printVec(v);

        // 복제마법 끝내기
        // copyFish에있는_것들빼와서 그대로 v에추가
        for (auto tp : copyFishVec) {
            auto [fs,r,c] = tp;
            newVec[r][c].push_back({fs.dir});
        }
        // 최종뉴벡터 v로
        v = newVec;
    }

    // 정답 출력
    ll acc =0ll;
    for (int r=0;r<4;r++) {
        for (int c=0;c<4;c++) {
            acc += v[r][c].size();
        }
    }
    cout << acc;


}