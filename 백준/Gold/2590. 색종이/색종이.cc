#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <limits.h>
#include <queue>
#define ll long long

using namespace std;

class page{
public:
    bool empty = true;
    bool full_6 = false;
    vector<vector<int>> block;
    page() {
        block = vector<vector<int>>(6,vector<int>(6,0));
    }

    bool is_ok(int y, int x, int size){
        for (int i = y; i<y+size; i++) {
            for (int j =x; j<x+size;j++) {
                if (block[i][j] == 1) return false;
            }
        }
        return true;
    }

    // 못 놓으면 false 리턴
    bool putPaper(int size) {
        if (size == 6 && empty) {
            full_6 = true;
            empty = false;
            return true;
        } else if (full_6) {
            return false;
        }
        // 놓을 수 있는 자리 탐색
        for (int i =0; i<6;i++) {
            if (i+size>6) break;
            for (int j =0; j<6; j++) {
                if (j+size > 6) break;
                if (is_ok(i,j,size)) {
                    for (int k = 0; k<size; k++) {
                        fill_n(block[i+k].begin()+j,size,1);
                        empty = false;
                    }
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v(7); // 남은 색종이 수
    for (int i =1;i<=6;i++) {
        int t; cin >> t;
        v[i] = t;
    }

    vector<page> p(1);
    for (int curSize = 6; curSize >=1; curSize--) {
        while (v[curSize] > 0) {
            lb3:
            for (int i =0; i<p.size(); i++) {
                lb:
                bool putFinish = p[i].putPaper(curSize);
                if (putFinish) { // 성공한 경우 
                    v[curSize]--;
                    goto lb4;
                }
                // 실패한 경우
                if (i == p.size()-1) {
                    p.push_back(page());
                }
                continue;
            }
            lb4:
            if (v[curSize] == 0) break;
        }
    }

    if (p.size() == 1 && p[0].empty) {
        cout << 0;
    } else {
        cout << p.size();
    }

}