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

using namespace std;


// 0 : 전부 0
// 1 : 전부 1
// -1 : 오류
int is_finish(vector<vector<int>>& v, int y, int x, int w) {
    if (w == 1) {
        return v[y][x];
    }
    int a = v[y][x];
    for (int i =y; i<y+w; i++) {
        for (int j =x; j<x+w; j++) {
            if (v[i][j] != a) return -1;
        }
    }
    return a;
}

string dfs(vector<vector<int>>& v, int y, int x, int want_size) {
    if (want_size == 1) {
        string ans = "(";
        ans.append(to_string(v[y][x]));
        ans.append(to_string(v[y][x+1]));
        ans.append(to_string(v[y+1][x]));
        ans.append(to_string(v[y+1][x+1]));
        ans.append(")");
        return ans;
    }
    string ans = "(";
    int p1_x = x, p1_y = y;
    int p2_x = x+want_size, p2_y = y;
    int p3_x = x, p3_y = y+want_size;
    int p4_x = x + want_size, p4_y = y + want_size;
    int ans_1 = is_finish(v,p1_y,p1_x,want_size);
    int ans_2 = is_finish(v,p2_y,p2_x,want_size);
    int ans_3 = is_finish(v,p3_y,p3_x,want_size);
    int ans_4 = is_finish(v,p4_y,p4_x,want_size);
    if (ans_1 != -1) {
        ans.append(to_string(ans_1));
    } else ans.append(dfs(v,p1_y,p1_x,want_size/2));
    if (ans_2 != -1) {
        ans.append(to_string(ans_2));
    } else ans.append(dfs(v,p2_y,p2_x,want_size/2));
    if (ans_3 != -1) {
        ans.append(to_string(ans_3));
    } else ans.append(dfs(v,p3_y,p3_x,want_size/2));
    if (ans_4 != -1) {
        ans.append(to_string(ans_4));
    } else ans.append(dfs(v,p4_y,p4_x,want_size/2));
    ans.append(")");
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h; cin >> h;
    if (h == 1) {
        int tmp;
        cin >> tmp;
        cout << tmp;
        return 0;
    }
    vector<vector<int>> v(h,vector<int>(h));
    for (int i =0;i<h;i++) {
        for (int j =0;j<h;j++) {
            char c; cin >> c;
            v[i][j] = (int)(c-'0');
        }
    }
    bool ok = true;
    int a = v[0][0];
    for (int i =0;i<h;i++) {
        for (int j =0;j<h;j++) {
            if (v[i][j] != a) {
                ok =false;
                break;
            }
        }
    }
    if (ok) {
        cout << a;
        return 0;
    }

    int want_size = h/2;
    string ans = dfs(v,0,0,want_size);
    cout << ans;
}