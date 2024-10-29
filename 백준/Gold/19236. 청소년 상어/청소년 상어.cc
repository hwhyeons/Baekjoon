#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;
// -----------------------------------------

#define PI 3.141592

pair<int, int> rotate(int y, int x) {
    int degree = -45;
    double rad = degree * (PI / 180);
    double newX = x * cos(rad) - y * sin(rad);
    double newY = x * sin(rad) + y * cos(rad);
    return { round(newY),round(newX) };
}

//pair<int, int> rotate(int y, int x) {
//    if (y == 1) {
//        if (x == 1) return { 0,1 };
//        if (x == 0) return { 1,1 };
//        if (x == -1) return { 1, 0 };
//    } else if (y == 0) {
//        if (x == 1) return { -1,1 };
//        if (x == -1) return{ 1,-1 };
//    } else if (y == -1) {
//        if (x == -1) return { 0,-1 };
//        if (x == 0) return { -1,-1 };
//        if (x == 1) return { -1,0 };
//    }
//    throw "err";
//}

class Fish {
public:
    int fishNumber;
    int dy; // 물고기의 Y축 방향벡터
    int dx; // 물고기의 X축 방향벡터
    bool dead; // 죽었는지 여부

    // 반시계 45도 회전
    void rotateCCW() {
        auto [newDy, newDx] =  rotate(this->dy,this->dx);
        this->dy = newDy;
        this->dx = newDx;
    }
};

//vector<vector<Fish*>> v(4,vector<Fish*>(4,nullptr));

//vector<Fish*> fishVectorByOrder(17); // 1번부터 시작

class CurrentShark {
public:
    int y; // 상어의 Y좌표
    int x; // 상어의 X좌표
    int dy; // 상어의 Y축 방향벡터
    int dx; // 상어의 X축 방향벡터
};
CurrentShark shark;



pair<int,int> getFishByNumber(vector<vector<Fish>>& v, int fishNumber) {
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            if (v[i][j].fishNumber == fishNumber) {
                return { i,j };
            }
        }
    }
    return { -1,-1 };
}

//void eat(int y, int x) {
//    if (v[y][x]->dead) throw "alread dead";
//    v[y][x]->dead = true;
//}

void changeSharkDirAndPos(Fish& info, int fishY, int fishX) {
    shark.dx = info.dx;
    shark.dy = info.dy;
    shark.y = fishY;
    shark.x = fishX;
}

// 바라보는 방향의 인접 물고기 리턴 (또는 죽은 물고기)
//Fish* getAdjFish(Fish* curFish) {
//    auto [y, x] = getFishYX(curFish);
//    int dy = curFish->dy;
//    int dx = curFish->dx;
//    int ny = y + dy;
//    int nx = x + dx;
//    // 아예 벗어나는 경우
//    if (ny < 0 || nx < 0 || nx >= 4 || ny >= 4) return nullptr; 
//    // 상어의 위치인 경우
//    if (ny == shark.y && nx == shark.x) {
//        return nullptr;
//    }
//    return v[ny][nx];
//}


void rotateAllFish(vector<vector<Fish>>& v) {
    for (int fishNum = 1; fishNum <= 16; fishNum++) {
        auto [y, x] = getFishByNumber(v,fishNum);
        Fish& f = v[y][x];
        if (f.dead) continue; // 이미 죽은 물고기
        for (int cnt =0; cnt<8; cnt++) { // 어차피 8번 안에 나옴
            //Fish adjFish = getAdjFish(f); // 인접한 물고기 찾기
            int dy = f.dy;
            int dx = f.dx;
            int ny = y + dy;
            int nx = x + dx;

            // 아예 벗어나는 경우 -> 재 회전
            if (ny < 0 || nx < 0 || nx >= 4 || ny >= 4) {
                f.rotateCCW(); // 반시계 회전
                continue;
            } else if (ny == shark.y && nx == shark.x) { // 상어의 위치인 경우 -> 재회전
                f.rotateCCW();
                continue; 
            }
            // 물고기인경우 -> 두 물고기 교환
            swap(v[ny][nx], v[y][x]);
            break;
        }
    }
}

// 상어가 잡을 수 있는 물고기
void makeAvailableFishPosList(vector<pair<int, int>>& v_ref, vector<vector<Fish>>& vec) {
    int sharkY = shark.y;
    int sharkX = shark.x;
    int sharkDY = shark.dy;
    int sharkDX = shark.dx;
    for (int i = 1; i <= 4; i++) {
        int ny = sharkY + i * sharkDY;
        int nx = sharkX + i * sharkDX;
        if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) break;
        if (vec[ny][nx].dead) continue; // 이미 죽은 물고기는 못잡음
        v_ref.push_back({ ny,nx });
    }

}

int deep = 0;
int eatAndRotate(vector<vector<Fish>>& vec, int eatY, int eatX) {
    auto copy_v = vec;
    Fish fishInfo = copy_v[eatY][eatX];
    
    // 물고기 죽이기
    copy_v[eatY][eatX].dead = true;
    int acc = fishInfo.fishNumber; // 누적 갱신
    CurrentShark beforeShark = shark;
    changeSharkDirAndPos(fishInfo,eatY,eatX); // 상어 방향전환 및 위치 변경
    rotateAllFish(copy_v); // 모든 물고기 방향전환
    vector<pair<int, int>> availableFishPosList; // 상어가 이동할 수 있는 위치
    makeAvailableFishPosList(availableFishPosList,copy_v); // availableFishPosList받아오기;
    //int bestLocalAcc = 0;
    vector<int> localArr;
    localArr.push_back(0);
    for (auto& p : availableFishPosList) {
        auto [fishY, fishX] = p;
        deep++;
        localArr.push_back(eatAndRotate(copy_v, fishY, fishX));
        deep--;
    }
    //rotateAllFishReverse(); // 모든 물고기 방향전환 역방향
    // "물고기" 되살리기
    //v[eatY][eatX]->dead = false;
    // 상어 역방향 되살리기
    //changeSharkDirAndPosReverse();
    shark = beforeShark; // 상어 역방향 되살리기
    int rt = acc + *max_element(localArr.begin(),localArr.end());
    //cout << "깊이 " << deep << " : " << *max_element(localArr.begin(), localArr.end()) << "\n";
    return rt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<Fish>> v(4, vector<Fish>(4));
    // 초기 물고기 
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            int a1, d;
            cin >> a1 >> d;
            //Fish* f = new Fish;
            Fish& f = v[i][j];
            f.dead = false;
            f.fishNumber = a1;
            int dy, dx;
            if (d == 1 || d == 2 || d == 8) {
                dy = -1;
            } else if (d == 3 || d == 7) {
                dy = 0;
            } else {
                dy = 1;
            }

            if (d == 2 || d == 3 || d == 4) {
                dx = -1;
            } else if (d == 1 || d == 5) {
                dx = 0;
            } else {
                dx = 1;
            }
            f.dy = dy;
            f.dx = dx;
            v[i][j] = f;
            //fishVectorByOrder[a1] = f;
        }
    }
    int best = eatAndRotate(v,0,0);
    cout << best;
}