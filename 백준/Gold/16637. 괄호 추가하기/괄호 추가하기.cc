#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <bitset>
typedef long long ll;
using namespace std;

// -----------------------------------------
// -----------------------------------------
// -----------------------------------------
int N;
ll maxAnswer = -2300000000LL;
string s;

ll cal(string num1, string num2, string op) {
    ll n1 = stoll(num1);
    ll n2 = stoll(num2);
    if (op == "+") {
        return n1 + n2;
    } else if (op == "-") {
        return n1 - n2;
    } else if (op == "*") {
        return n1 * n2;
    } else {
        throw "err";
    }
}

ll calculate(vector<int>& idxs) {
    string newStr(s); // 복사
    if (idxs.size() % 2 == 1) throw "err";

    // 역순으로 추가해야 인덱스 문제 X
    for (int i = idxs.size() - 1; i >= 0; i-=2) {
        int idxClose = idxs.at(i);
        int idxOpen = idxs.at(i-1);
        newStr.insert(idxClose+1, ")");
        newStr.insert(idxOpen, "(");
    }
    
    // 실제 string 계산
    // stack이용
    deque<string> d;
    for (size_t i = 0; i < newStr.size(); i++) {
        string ch = newStr.substr(i, 1);
        if ('0' <= ch[0] && ch[0] <= '9') {
            d.push_back(ch);
            continue;
        } else if (ch == "(") {
            d.push_back(ch);
        } else if (ch == ")") {
            assert(d.size() >= 4);
            //d.pop_back(); // (,3,+,4,) 에서 맨마지막 제거 : deque에 안넣었으므로 할 필요가 없음
            string numLastStr = d.back(); d.pop_back();
            string op = d.back(); d.pop_back();
            string numFirstStr = d.back(); d.pop_back();
            d.pop_back(); // 여는 괄호 제거
            ll num = cal(numFirstStr, numLastStr, op);
            string tmp = to_string(num);
            d.push_back(tmp);
        } else {
            d.push_back(ch);
        }
    }

    // 괄호가 없는 스택 -> 바로바로 계산
    while (!d.empty()) {
        if (d.size() == 1) {
            ll finalAnswer = stoll(d.front());
            return finalAnswer;
        }
        string num1 = d.front(); d.pop_front();
        string op = d.front(); d.pop_front();
        string num2 = d.front(); d.pop_front();
        ll tmp = cal(num1, num2, op);
        d.push_front(to_string(tmp));
    }

}

void dfs(vector<int>& idxs, int start) {
    if (start % 2 == 1) throw "Err";
    if (start >= N - 1) {
        ll ans = calculate(idxs);
        maxAnswer = max(maxAnswer, ans);
        return;
    }

    dfs(idxs, start + 2); // 이번 깊이에서 추가 안하는 경우 계산

    for (int i = start; i <= N - 3; i+=2) {
        //if (i in idxs) continue; // 이미 포함된 경우
        idxs.push_back(i);
        idxs.push_back(i+2);
        dfs(idxs, i +4);
        idxs.pop_back();
        idxs.pop_back();
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> s;
    vector<int> idxs;
    dfs(idxs,0);
    cout << maxAnswer;
}