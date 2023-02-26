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
#include <valarray>

using namespace std;

int h,w;
int answer = -1;

bool is_sqrt(int number) {
    double s = sqrt((double)number);
    if ((int)s != s) return false;
    int sq = (int)s * (int)s;
    if (sq != number) return false;
    else return true;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    vector<vector<string>> ar(h,vector<string>(w));
    
    for (int i =0; i<h; i++) {
        string s;
        cin >> s;
        for (int j =0; j<s.size(); j++) {
            ar[i][j] = s.substr(j,1);
        }
    }

    // bool one_time =true;
    // starting:
    // x, y : 시작 지점
    for (int y=0; y<h; y++) {
        for (int x=0;x<w; x++) {
            // dr , dc : 증가 r,c
            for (int dr = h; dr>=-h; dr--) {
                for (int dc = w; dc>=-w; dc--) {
                    if (dr == 0 && dc == 0) continue;
                    string tmp = "";
                    int r = y;
                    int c = x;
                    while (true) {
                        tmp += ar[r][c];
                        int number = stoi(tmp);
                        if (is_sqrt(number)) {
                            answer = max(answer,number);
                        }
                        r += dr;
                        c += dc;
                        if (c >= w || r >= h || c <0 || r <0) break; 
                    }
                }
            }
        }
    }
    // if (!one_time) goto ans;
    // else one_time = false;
    // for (int i =0; i<ar.size(); i++) {
    //     reverse(ar[i].begin(),ar[i].end());
    // }
    // goto starting;
    // ans:
    cout << answer;
}
