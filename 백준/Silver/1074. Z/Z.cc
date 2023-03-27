#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <map>

#define ll long long

using namespace std;

int n,r,c;
ll pow2(int num);

void f(ll row, ll col, ll size, ll startCount) {
    if (size == 2) {
        if (row == r && col == c) {
            cout << startCount;
        } else if (row == r && col+1 == c) {
            cout << startCount+1;
        } else if (row+1 == r && col == c) {
            cout << startCount+2;
        } else {
            cout << startCount+3;
        }
        exit(0);
    }
    ll q = size/2;
    ll next_base = (size*size)/4;
    if (r < row+q && c < col+q) {
        f(row,col,q,startCount);
    } else if (r < row+q) {
        f(row,col+q,q,startCount+next_base);
    } else if (r < row+2*q && c < col+q) {
        f(row+q,col,q,startCount+next_base*2);
    } else if (r < row+2*q) {
        f(row+q,col+q,q,startCount+next_base*3);
    }
}

ll pow2(int num) {
    if (num == 0) return 1LL;
    if (num == 1) return 2LL;
    ll cur = 1;
    for (int i = 0; i < num; ++i) {
        cur *= 2;
    }
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> r >> c;
    ll start = pow2(n);
    f(0,0,start,0LL);

}
