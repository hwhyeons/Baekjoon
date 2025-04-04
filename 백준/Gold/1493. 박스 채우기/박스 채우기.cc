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



// key : 2의 n승의 n / value : 개수
vector<int> cnt(20,0);

int ans = 0;

// 2의 제곱수인지
bool is_2x(int num) {
    // if (num ==1) return true; // 1도 참
    // if (num%2 == 0) return true;
    // return false;
    if (num ==1) return true; // 1도 참
    if (num==2) return true;
    if (log2(num) == (int)log2(num)) return true;
    return false;

    // 만약 num이 8인 경우
    // sqr = 2
    // sqrt(num) == 2.0
    // int sqr = sqrt(num); //
    // if (sqrt(num) == sqr) {
    //     return true;
    // } else {
    //     return false;
    // }
}

int getBestIndex(int num) {
    // 최적 벡터 인덱스 (2의 N승의 N)을 리턴
    // 예를들어 num이 10이면 가장 가까운건 2^3이므로 3리턴
    // num 1 -> 0
    // num 2 -> 1
    // num 4 -> 2
    // num 8 -> 3
    return (int)log2(num);
}

void f(int l, int w, int h) {
    if (l <=0 || w<=0 || h<=0) return;

    // 모든 변의 길이가 같고 2의 배수인 경우
    int bestMax2 = getBestIndex(min(h,min(l,w)));
    if (l == w && w == h && l == h && is_2x(l)) {
        if (cnt[bestMax2] == 0) { // 최적은 길이가 8인 큐브인데 8인 큐브가 없는 경우
            // 1개 짜리가 없는 경우 -> Fail
            if (l == 1) {
                cout << "-1";
                exit(0);
            }
            // 다시 8등분하기
            int newLen = l/2;
            for (int j=0; j<8; j++) {
                f(newLen,newLen,newLen);
            }
        } else {
            cnt[bestMax2]--;
            ans++;
        }
        return;
    }

    // 전부 쪼개기
    // 여기서는 만약 9x19x11이런 형태라서 4를 쓰는데 4가 없더라도 일단 진행함
    int r = pow(2,bestMax2); // bestMax2가 3이라면 8이 실제 가장 큰 한변의 길이임
    f(r,r,r); // 8
    f(r,w-r,r); // 4
    f(r,r,h-r); // 4
    f(r,w-r,h-r); // 2
    f(l-r,w-r,r); // 2
    f(l-r,r,h-r); // 2
    f(l-r,w-r,h-r); // 1
    f(l-r,r,r); // 4
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int LENGTH,WIDTH,HEIGHT;
    cin >> LENGTH >> WIDTH >> HEIGHT;
    int QUBE_CATE;
    cin >> QUBE_CATE;
    for (int i = 0; i < QUBE_CATE; ++i) {
        int Ai,Bi;
        cin>> Ai >> Bi;
        // int real = pow(2,Ai);
        cnt[Ai] = Bi;
    }
    f(LENGTH,WIDTH,HEIGHT);
    cout << ans;
}