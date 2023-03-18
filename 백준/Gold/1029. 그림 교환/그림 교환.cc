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


// // 특정 경로 , 방문 순서, 이전 값 저장
// class information {
// public:
//     string visit;
//     string path;
//     int beforeValue;

//     information(int nodeCount) {
//         visit = "";
//         for (int i =1;i<=nodeCount;i++) {
//             visit.append("0");
//         }
//     }

//     bool operator == (const information& i) {
//         if (i.visit == this->visit && this->path == i.path && this->beforeValue == i.beforeValue) return true;
//         else return false;
//     }
// };


unordered_map<string,int> m; // (방문문자열+
vector<vector<int>> v;

int get_before_value(string& s){
    return stoi(s.substr(s.size()-1));
}
int dfs(int cur, string inform) {
    if (m.count(inform)) {
        return m[inform];
    }

    inform[3+cur] = '1';
    int beforeValue = get_before_value(inform);
    inform[inform.size()-1] = (char)(beforeValue)+'0';
    int mx = 0;
    for (int i =0; i<v[cur].size(); i++) {
        if (cur == i || v[cur][i] < beforeValue || inform[3+i] == '1') continue;
        string s2(inform);
        int numberTmp = i;
        if (numberTmp < 10) {
            s2[0] = '0';
            s2[1] = (char)numberTmp+'0';
        } else {
            s2[0] = 1;
            s2[1] = ((char)numberTmp%10)+'0';
        }
        s2[3+i] = '1';
        s2[s2.size()-1] = (char)v[cur][i]+'0';
        auto tmp = dfs(i,s2);
        mx = max(mx,tmp);
    }
    m[inform] = mx+1;
    return mx+1; // !! 주의 : 리턴 하는 값은 몇명 보유인지
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    v = vector<vector<int>>(N,vector<int>(N));
    for (int i =0;i<N; i++) {
        for (int j =0;j<N; j++) {
            char tmp; cin >> tmp;
            v[i][j] = (int)(tmp-'0');
        }
    }
    // "현재노드(00~14) 방문노드 " 
    string visit = "00 ";
    for (int i =1;i<=N;i++) {
        visit.append("0");
    }
    visit.append(" ");
    visit.append("0");
    
    int mx = dfs(0,visit);
    cout << mx;
    
}