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
#include<deque>
typedef long long ll;
typedef long double ld;
using namespace std;

int N,M;


int ans1 = 0;
int ans2 = 0;
int ans3 = 0;

int ry;
int rx;
int dy;
int dx;
int ADD_CONST;
int cur_add;
bool finishRotate;
void clearIndex() {
    ry = (N)/2;
    rx = (N)/2;
    dy=0;
    dx=-1;
    ADD_CONST = 1;
    cur_add = 0;
    finishRotate= false;
}


pair<int,int> getNextIndex() {
    if (finishRotate) return {-1,-1};
    cur_add++;
    ry += dy;
    rx += dx;
    if (cur_add == ADD_CONST) {
        cur_add = 0;
        // 왼쪽:아래로
        if (dy==0 && dx==-1) {
            dy=1;
            dx=0;
        } else if (dy==1 && dx==0) { //아래쪽:오른쪽;ADD_CONST증분;
            dy=0;
            dx=1;
            ADD_CONST++;
        } else if (dy==0 && dx==1) { // 오른쪽:위로;
            dy=-1;
            dx=0;
        } else if (dy==-1 && dx==0) {
            dy=0;
            dx=-1;
            ADD_CONST++;
        } else {
            throw "err";
        }
    }
    if (ry==0 && rx==0) {
        finishRotate=true;
    }
    return {ry,rx};
}

void doMagic(vector<vector<int>>& v, int di, int si) {
    int dy,dx;
    if (di==1) { // 위 공격
        dy=-1;
        dx=0;
    } else if (di==2) { // 아래 공격
        dy=1;
        dx=0;
    } else if (di==3) { // 왼쪽 공격
        dy=0;
        dx=-1;
    } else if (di==4) { // 오른족
        dy=0;
        dx=1;
    } else {
        throw "err";
    }

    int cy = N/2;
    int cx = N/2;
    int s_cnt = 0;

    while (true) {
        int ny = cy+dy;
        int nx = cx+dx;
        if (ny<0 || nx <0 || ny>=N || nx>=N || s_cnt == si) break;
        v[ny][nx] = 0;
        cy = ny;
        cx = nx;
        s_cnt++;
    }
    return;
}

 void makeDequeWithNoZero(vector<vector<int>>& v,deque<tuple<int,int,int>>& d) {
    clearIndex();
    while (true) {
        auto [y,x] = getNextIndex();
        // cout << y << x << "\n";
        if (y==-1) break;
        if (v[y][x] ==0)continue;
        d.push_back({y,x,v[y][x]});
    }
}

//


void newExplod(deque<tuple<int,int,int>>& d, deque<pair<int,int>>& nd) {
    for (int i=0;i<d.size();i++) {
        auto [y,x,k] = d[i];
        if (nd.size()==0) {
            nd.push_back({k,1});
        } else {
            auto [num,topCnt] = nd.back();
            if (num == k) {
                nd.pop_back();
                nd.push_back({num,topCnt+1});
            } else {
                nd.push_back({k,1});
            }
        }
    }

    while (true) {
        int ridx = nd.size()-1;
        bool tfRemove = false;
        while (ridx >= 0 && !nd.empty()) {
            if (ridx >= (int)(nd.size())) ridx = (int)(nd.size())-1;
            auto [num,cnt] = nd[ridx];
            if (cnt>=4) {
                int tv = num;
                tfRemove = true;
                if (tv == 1) {
                    ans1+=cnt;
                } else if (tv==2) {
                    ans2+=cnt;
                } else if (tv==3) {
                    ans3+=cnt;
                } else {
                    throw "err";
                }
                // cout << "size : " << nd.size() << "\n";
                nd.erase(nd.begin()+ridx);
                // cout<< "ans1 + ans2 + ans3 : " << ans1+ans2*2+3*ans3 << "\n";
            } else {
                ridx--;
            }
        }
        if (tfRemove) {
            // 값 합치기
            for (int j=1;j<(int)(nd.size());j++) {
                auto [a1,b1] = nd[j];
                auto [a2,b2] = nd[j-1];
                if (a1==a2) {
                    nd[j-1] = {a1,b1+b2};
                    nd.erase(nd.begin()+j);
                    j--;
                    // cout << "size : " << nd.size() << "\n";
                }
            }
            // cout << "size : " << nd.size() << "\n";
            continue;
        }
        break;
    }





}
// void explodeUntil(deque<tuple<int,int,int>>& d) {
//     int idx =0;
//     int sameStart = 0;
//     int sameCount = 1;
//
//     // 반복문끝나고도sameCount4이상이면터트리기;
//     while (idx < (int)(d.size()-1)) { // 5개라면 0,1,2,3,4 인덱스에서 1번인덱스까지만 동작
//         // cout << "idx " << idx << "\n";
//         auto [t1,t2,v0] = d[idx];
//         auto [t3,t4,v1] = d[idx+1];
//         if (v0==v1) {
//             sameCount++;
//             idx++;
//         } else {
//             // 다른 경우 + 개수 4개 이상이면 지우기
//             if (sameCount>=4) {
//                 // 답부터
//                 auto [ty,tx,tv] = d[sameStart];
//                 if (tv == 1) {
//                     ans1+=sameCount;
//                 } else if (tv==2) {
//                     ans2+=sameCount;
//                 } else if (tv==3) {
//                     ans3+=sameCount;
//                 } else {
//                     throw "err";
//                 }
//                 cout << "폭발 : " << ans1+ans2*2+3*ans3 << "\n";
//
//                 d.erase(d.begin()+sameStart,d.begin()+sameStart+sameCount);
//                 // idx-=sameCount+1;
//                 idx=0;
//                 if (idx <0) idx=0;
//             } else {
//                 idx++;
//             }
//             sameCount = 1;
//             sameStart=idx;
//         }
//     }
//
//     // 다 끝났지만 남은 경우
//     if (sameCount>=4) {
//         auto [ty,tx,tv] = d[sameStart];
//         if (tv == 1) {
//             ans1+=sameCount;
//         } else if (tv==2) {
//             ans2+=sameCount;
//         } else if (tv==3) {
//             ans3+=sameCount;
//         } else {
//             throw "err";
//         }
//         cout << "폭발 : " << ans1+ans2*2+3*ans3 << "\n";
//
//         d.erase(d.begin()+sameStart,d.begin()+sameStart+sameCount);
//         idx-=sameCount+1;
//         if (idx <0) idx=0;
//         sameCount = 1;
//         sameStart=idx;
//     }
//
// }

void makeGroup(deque<tuple<int,int,int>>& beforeD, deque<int>& newDeque) {
    int idx=0; // 이전 덱의 인덱스
    int groupNum = -1;
    int groupMemberCnt = 0;
    // 새 덱은 48개까지만
    while (newDeque.size()<(N*N-1) && idx<(int)(beforeD.size())) {
        auto [ty,tx,tv] = beforeD[idx];
        // cout << "ty tx tv " << tv << "\n";

        // 현재 그룹이 없는 경우
        if (groupNum==-1) {
            // cout << "새그룹형성\n";
            groupNum = tv;
            groupMemberCnt=1;
            idx++;
        } else if (groupNum == tv) {
            // cout << "그룹원 추가\n";
            groupMemberCnt++; // 그룹원으로 추가
            idx++;
        } else if (groupNum != tv) {
            // 뉴덱에추가
            // cout<< "뉴덱에 추가 : " << groupMemberCnt << " " << groupNum << "\n";
            newDeque.push_back(groupMemberCnt);
            if (newDeque.size()>=(N*N-1)) break; // 중간이라도 덱이 꽉찬 경우
            newDeque.push_back(groupNum);

            // 새그룹초기화
            // cout << "새그룹형성\n";
            groupNum = tv;
            groupMemberCnt = 1;
            idx++;
        }
    }

    // 남은 그룹이 있다면 설정
    if (groupNum != -1) {
        if (newDeque.size()<(N*N-1)) {
            newDeque.push_back(groupMemberCnt);
        }
        if (newDeque.size()<(N*N-1)) {
            newDeque.push_back(groupNum);
        }
    }

}

void resetVectorWithDeqeue(deque<int>& newDeque, vector<vector<int>>& v) {
    clearIndex();
    int dequeIdx = 0;
    while (dequeIdx < newDeque.size()) {
        auto [y,x] = getNextIndex();
        v[y][x] = newDeque[dequeIdx];
        dequeIdx++;
        // if (v[y][x] ==0)continue;
        // d.push_back({y,x,v[y][x]});
    }

    // 덱에서 빈거 다 0으로 채우기
    while (true) {
        auto [y,x] = getNextIndex();
        if (y==-1) break;
        v[y][x] = 0;
    }
}

void printAllDeque(deque<tuple<int,int,int>>& d) {
    for (auto it : d) {
        auto [y,x,t] = it;
        cout << "(" << y <<","<< x <<") " << t << "\n";
    }
    cout << "\n";

}

void ndToBd(deque<pair<int,int>>& nd,deque<tuple<int,int,int>>& bd) {
    for (int i=0;i<nd.size();i++) {
        auto [num,cnt] = nd[i];
        for (int t=0;t<cnt;t++) {
            bd.push_back({-1,-1,num});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    vector<vector<int>> v(N,vector<int>(N));
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> v[i][j];
        }
    }
    // deque으로 전환
    // deque<int> d; // 값

    for (int turn=0;turn<M;turn++) {
        clearIndex();
        // 마법 사용
        int di, si;
        cin >> di >> si;
        // 마법시전
        doMagic(v,di,si);

        deque<tuple<int,int,int>> d;
        makeDequeWithNoZero(v,d);
        // 당기기 -> makeDequeWithNoZero()에서 당기므로 필요X
        // pullAll(d);
        // explodeUntil(d);
        deque<pair<int,int>> nd;
        newExplod(d,nd);
        // printAllDeque(d);
        deque<tuple<int,int,int>> bd;
        ndToBd(nd,bd);
        deque<int> newDeque;
        makeGroup(bd,newDeque);

        // resetVectorWithDeqeue
        resetVectorWithDeqeue(newDeque,v);

    }

    cout<< 1*ans1 + 2*ans2 + 3*ans3;

    // while (true) {
    //     auto [y,x] =getNextIndex();
    //     // cout << tmp.first << " " << tmp.second << "\n";
    //     if (y==-1) break;
    //     d.push_back(tmp_vector[y][x]);
    // }
    // cout << d.size();

}