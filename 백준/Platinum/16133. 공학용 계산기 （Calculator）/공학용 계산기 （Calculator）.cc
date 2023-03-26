#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

#define ll long long

using namespace std;


ll num;
bool is_end;

void get_token();
ll factor();
ll get_expression();
ll term();
ll power();

// 뒤에 숫자가 나옴을 보장된 상태에서 숫자 뽑기
ll get_number_only() {
    ll result = 0LL;
    char ch = getchar();
    result = (int)(ch-'0');
    while (true) {
        ch = getchar();
        if (isdigit(ch)) {
            result = 10*result + ((int)(ch-'0'));
        } else {
            ungetc(ch,stdin);
            break;
        }
    }
    return result;
}
ll root(){
    char ch = getchar();
    ll result;
    if (ch == '(') {
        result = get_expression();
        getchar(); // 오른쪽 괄호 먼저 읽어버리기
    } else if (isdigit(ch)) { // 숫자인 경우
        ungetc(ch,stdin);
        result = get_number_only(); // 뒤에 숫자가 나옴을 보장
    } else {
        cout << "오류";
    }
    return result;
}


ll sqrt_(ll n) {
    long double k = sqrtl((long double)n);
    if (k < 0) {
        k = ceil(k);
    } else {
        k = floor(k);
    }
    return (ll)(k);
}

// 밑 / 지수
ll pow_(ll n, ll exp) {
    if (exp == 0) {
        return 1LL;
    }
    ll ans = 1LL;
    for (int i = 1; i <= exp; ++i) {
        ans *= n;
    }
    return ans;
}

ll power() {
    char ch = getchar();
    ll result;
    if (ch == '#') {
        result = sqrt_(power());
    } else {
        ungetc(ch,stdin);
        result = root();
    }
    return result;
}


bool is_next_power() {
    if (is_end) {
        return false;
    }
    char ch = getchar();
    ungetc(ch,stdin);
    if (ch == '^') {
        return true;
    } else {
        return false;
    }
}


ll factor(){
    ll result = power();
    bool next_power = is_next_power();
    if (next_power) {
        getchar(); // 한글자 스킵 ( ^ 글자 읽기)
        result = (ll)(powl(result,factor()));
    }
    return result;
}

/*
 *     ll result;
    result = term();
    char ch = getchar();
    while(ch == '+' || ch == '-'){
        bool is_plus = ch == '+' ? true : false;
        ll exp = term();
        if (is_plus) {
            result += exp;
        } else {
            result -= exp;
        }
        ch = getchar();
    }
    ungetc(ch,stdin);
 */

ll term(){
    ll result;
    result = factor();
    char ch = is_end ? -1 : getchar();
    while (ch == '*' || ch == '/') {
        bool is_star = ch == '*' ? true : false;
        ll factor_tmp = factor();
        if (!is_star) {
            if (result < 0 && factor_tmp > 0) { // 음수를 양수로 나누는 경우
                result*=-1;
                result/=factor_tmp;
                result*=-1;
            } else {
                result /= factor_tmp;
            }
        } else {
            result*=factor_tmp;
        }
        ch = getchar();
    }
    ungetc(ch,stdin);
    return result;
}

ll get_expression() {
    ll result;
    result = term();
    char ch = getchar();
    while(ch == '+' || ch == '-'){
        bool is_plus = ch == '+' ? true : false;
        ll exp = term();
        if (is_plus) {
            result += exp;
        } else {
            result -= exp;
        }
        ch = getchar();
    }
    ungetc(ch,stdin);
    return result;
}


int main()
{
//    auto a = powl(1,100000000000000000LL);
//    cout << a;
        ll result;
    result = get_expression();
    cout << result;
//    printf("%ld",result);
}
