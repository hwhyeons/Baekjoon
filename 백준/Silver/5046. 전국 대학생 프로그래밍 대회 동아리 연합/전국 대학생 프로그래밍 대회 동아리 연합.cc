#include <algorithm>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <limits.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,B,H,W;
    cin >> N >> B >> H >> W;
    int mn = INT_MAX;
    for (int i = 0; i < H; ++i) {
        int price; cin >> price;
        for (int j = 0; j < W; ++j) {
            int tmp; cin >> tmp;
            if (tmp >= N) {
                if (price*N <= B) {
                    mn = min(mn,price*N);
                }
            }
        }
    }
    if (mn == INT_MAX) {
        cout << "stay home";
    } else {
        cout << mn;
    }
}
