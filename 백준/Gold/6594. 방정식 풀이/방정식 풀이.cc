#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <unordered_set>

typedef long long ll;
using namespace std;

pair<int, int> parse_expression();

string line;
int idx = 0;

char top() {
    if (idx < line.size()) {
        return line[idx];
    }
    return NULL;
}

void skip_token() {
    idx++;
}

int parse_number() {
    int startIdx = idx;
    int cnt = 0;
    char tok;
    while (tok = top()) {
        if (tok >= '0' && tok <= '9') {
            skip_token();
            cnt++;
            continue;
        } else {
            break;
        }
    }

    if (cnt == 0) throw "err3";
    string numberStr = line.substr(startIdx, cnt);
    return stoi(numberStr);
}

pair<int, int> parse_factor() {
    auto tok = top();
    if (tok == 'x') {
        skip_token();
        return { 1,0 };
    } else if (tok == '(') {
        skip_token();
        auto e1 = parse_expression();
        auto tok_new = top();
        if (tok_new != ')') throw "err";
        skip_token();
        return e1;
    } else {
        return { 0,parse_number() };
    }
}

pair<int, int> parse_term() {
    auto f1 = parse_factor();
    char top_tok = top();
    if (top_tok == '*') {
        skip_token();
        auto f2 = parse_factor();
        // 3*x라면 첫번째는 {0,3}이고 두번째는 {1,0}으로 오므로 1*3이 되어야함
        return { max(f1.first * f2.second,f1.second * f2.first),f1.second * f2.second };
    }
    return f1;
}


pair<int,int> parse_expression() {
    auto t1 = parse_term();
    pair<int, int> curVal = { t1.first,t1.second };
    while (1) {
        auto top_tok = top();
        if (top_tok == '+' || top_tok == '-') {
            skip_token();
            auto t2 = parse_term();
            if (top_tok == '+') {
                curVal = { curVal.first + t2.first, curVal.second + t2.second };
            } else {
                curVal = { curVal.first - t2.first,curVal.second - t2.second };
            }
            continue;
        }
        break;
    }
    return curVal;
}

void parse_line(string& line) {
    static int equationNumber = 0;
    equationNumber++;
    auto e1 = parse_expression();
    auto tok = top();
    if (tok != '=') throw "err2";
    skip_token();
    auto e2 = parse_expression();
    // X계수가 같은 경우
    cout << "Equation #" << equationNumber << "\n";
    if (e1.first == e2.first) {
        if (e1.second == e2.second) {
            cout << "Infinitely many solutions." << "\n\n";
        } else {
            cout << "No solution." << "\n\n";
        }
        return;
    }
    cout.precision(6);
    cout << fixed;
    ll x_const = e1.first - e2.first;
    ll con = e2.second - e1.second;
    double ans = (double)(con) / x_const;
    cout << "x = " << ans << "\n\n";
    cout.unsetf(ios::fixed);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (getline(cin, line)) {
        parse_line(line);
        idx = 0;
    }
}