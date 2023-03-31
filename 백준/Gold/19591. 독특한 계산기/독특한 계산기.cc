#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

bool read_finish = false;

bool is_number;
string oper;
string saved_num;

void get_tok() {
    is_number = false;
    ll result = 0LL;
    char ch = getchar();
    if (ch == EOF) {
        read_finish = true;
        return;
    }
    if (isdigit(ch)) {
        result = 10*result + ((int)(ch-'0'));
        while (true) {
            ch = getchar();
            if (isdigit(ch)) {
                result = 10*result + ((int)(ch-'0'));
            } else {
                if (ch == EOF) {
                    read_finish = true;
                    return;
                } else {
                    ungetc(ch,stdin);
                }
                break;
            }
        }
        is_number = true;
        saved_num = to_string(result);
    } else if (ch == EOF || ch == '\n') {
        read_finish = true;
    } else {
        oper = string(1,ch);
        is_number = false;
    }
}

string cal(string& s1, string& s2, string& op) {
    ll num1 = stoll(s1);
    ll num2 = stoll(s2);
    ll num3;
    if (op == "+"){
        num3 = num1+num2;
    } else if (op == "-") {
        num3 = num1-num2;
    } else if (op == "*") {
        num3 = num1*num2;
    } else {
        num3 = num1/num2;
    }
    return to_string(num3);
}

bool is_same_level(string& op1, string& op2) {
    if (op1 == op2) return true;
    bool op1_is_plus_minus = (op1 == "+" || op1 == "-");
    bool op2_is_plus_minus = (op2 == "+" || op2 == "-");
    if (op1_is_plus_minus == op2_is_plus_minus) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    deque<string> dq;
    char c_first = getchar();
    bool first_minus = false;
    if (c_first == '-') {
        first_minus = true;
    } else ungetc(c_first, stdin);
    get_tok(); // 처음에는 숫자 보장
    string f_num = saved_num;
    ll f_num_l = stoll(saved_num); // 불필요 한 것들 미리 제거 (ex: -0000000000)
    if (first_minus && f_num_l != 0) f_num.insert(0,"-");
    dq.push_back(f_num);
    while (true) {
        get_tok();
        if (read_finish) break;
        if (is_number) {
            dq.push_back(saved_num);
        } else {
            dq.push_back(oper);
        }
    }
    while (true) {
        if (dq.size() == 1) { // finish
            break;
        } else if (dq.size() == 2) { // 불가능
            throw 1;
        }
        string oper1 = dq[1];
        string oper2 = dq[dq.size()-2];
        if (is_same_level(oper1,oper2)) { // 동등한 경우에는 계산 해서 순위 결정
            ll cal1 = stoll(cal(dq[0],dq[2],oper1));
            ll cal2 = stoll(cal(dq[dq.size()-3],dq[dq.size()-1],oper2));
            if (cal1 >= cal2) {
                dq.pop_front();
                dq.pop_front();
                dq.pop_front();
                dq.push_front(to_string(cal1));
            } else {
                dq.pop_back();
                dq.pop_back();
                dq.pop_back();
                dq.push_back(to_string(cal2));
            }
        } else {
            // oper1 is win
            string tmp;
            if (oper1 == "*" || oper1 == "/") {
                tmp = cal(dq[0],dq[2],oper1);
                dq.pop_front();
                dq.pop_front();
                dq.pop_front();
                dq.push_front(tmp);
            } else { // oper2 is win
                tmp = cal(dq[dq.size()-3],dq[dq.size()-1],oper2);
                dq.pop_back();
                dq.pop_back();
                dq.pop_back();
                dq.push_back(tmp);
            }
        }
    }
    cout << dq[0];

}

