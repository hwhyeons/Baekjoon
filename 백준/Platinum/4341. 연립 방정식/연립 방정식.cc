#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
using namespace std;

int get_number(string &str, string want_xyz);
int get_const(const string &str);

string error = "";


vector<int> get_all_number(const string &s);


// 최대 공약수 (유클리드 호제법)
int get_gcd(int a, int b){
    int tmp, n;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}


string get_irreducible_fraction(int xy, int cs) {
    if (xy == 0) {
        throw string("can't denom is 0");
    } else if (cs == 0) { // 분자가 0인 경우
        return string("0");
    }
    bool set_minus = false;
    if (xy*cs < 0) { // 둘중 하나 음수
        set_minus = true;
    }
    xy = abs(xy);
    cs = abs(cs);
    int denom = xy;
    int numer = cs;

    int gcd = get_gcd(xy,cs);
    if (gcd == 0) {
        throw string("gcd cannot 0");
    }
    denom /= gcd;
    numer /= gcd;
    string ans = set_minus ? "-" : "";
    if (denom == 1) {// 분모가 1이면 부모 없이 리턴
        ans.append(to_string(numer));
    } else {
        ans.append(to_string(numer)+"/"+to_string(denom));
    }
    return ans;
}

// 전제 조건 : x,y 중에 하나는 0이고 하나는 0이 아닌 수여야함
string get_irreducible_fraction_auto(vector<int>& v) {
    if (v[0] == 0 && v[1] == 1) {
        throw string("two argument is zero");
    }
    if (v[0] == 0) { // x 계수가 0
        return get_irreducible_fraction(v[1],v[2]);
    } else { // y 계수가 0
        return get_irreducible_fraction(v[0],v[2]);
    }
}

void print_answer(string& x, string& y) {
    if (x=="") {
        cout << "don't know\n";
    } else {
        cout << x << "\n";
    }
    if (y==""){
        cout << "don't know\n";
    } else {
        cout << y << "\n";
    }
    cout << "\n";
}


// 0 = 0이나 2 + 2 = 0 + 4 처럼 모순이 없는 상수 식
bool is_safe_const_expression(const vector<int>& v) {
    if (v[0] == 0 && v[1] == 0 && v[2] == 0) return true;
    else return false;
}

bool is_x_only_exist(const vector<int>& v) {
    if (v[0] != 0 && v[1] == 0) return true;
    else return false;
}

bool is_y_only_exist(const vector<int>& v) {
    if (v[0] == 0 && v[1] != 0) return true;
    else return false;
}

// 식에 x +y = 4처럼 x,y둘다 존재
bool is_xy_exist(const vector<int>& v) {
    if (v[0] != 0 && v[1] != 0) return true;
    else return false;
}

// 기약분수 형태에서 분모 찾기
int get_denominator(string& s) {
    auto it = s.find('/');
    // 없을 때
    if (it == string::npos) return 1;
    int tmp = stoi(s.substr(it+1));
    if (tmp == 0) {
        throw string("str like 123/0 ");
    }
    return tmp;
}

// 기약분수 형태에서 분자 찾기
int get_numerator(string& s) {
    if (s == "0") return 0;
    auto it = s.find('/');
    // 없을 때 : 숫자 그대로가 분자
    if (it == string::npos) return stoi(s);
    return stoi(s.substr(0,it));
}

void multiply_vector(vector<int>& v, const int mu) {
    v[0]*=mu;
    v[1]*=mu;
    v[2]*=mu;
}

// 여기서 소수점 나오면 절대 안됨
int multiply_fraction(int denom, int numer, int base) {
    if (denom == 0) {
        throw string("multiply_fraction : denom cannot 0");
    }
    return numer * base / denom;
}


bool is_all_same(const vector<int>& v1,const vector<int>& v2) {
    // 이 함수는 x,y계수가 0이 아닌 경우에만 출력
    int cross1 = v2[0];
    int cross2 = v1[0];
    int y1 = v1[1]*cross1;
    int y2 = v2[1]*cross2;
    if (y1 == y2) return true;
    else return false;
}

// 전제 조건 : 식 두개 중에 지금 하나만 존재한다는 가정
// ex : 첫번째 식은 3 = 3이고 두번째 식은 x + y = 4인경우
void print_auto_only_one(vector<int>& v) {
    if (is_xy_exist(v)) { // 첫번째 식이 없는데 나머지 식에 x,y가 두개나 존재하면 모순
        print_answer(error,error);
    } else if (is_x_only_exist(v)) { // x만 존재하는 경우
        string x = get_irreducible_fraction(v[0],v[2]);
        print_answer(x,error);
    } else if (is_y_only_exist(v)) {
        string y = get_irreducible_fraction(v[1],v[2]);
        print_answer(error,y);
    } else {
        throw string("this function called only have more than 1 x or y");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t_cnt; string stmp;
    getline(cin,stmp);
    t_cnt = stoi(stmp);
    while (t_cnt--) {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        vector<int> v1 = get_all_number(s1);
        vector<int> v2 = get_all_number(s2);
        // 3 = 4 처럼 아예 모순인 경우 (이 경우에는 하나만 모순이여도 오답)
        if ((v1[0] == 0 && v1[1] == 0 && v1[2] != 0) || (v2[0] == 0 && v2[1] == 0 && v2[2] != 0)) {
            print_answer(error,error);
        }
        // 1번 2번 모두 모순이 없는 상수 식
        else if (is_safe_const_expression(v1) && is_safe_const_expression(v2)) {
            print_answer(error,error);
        }
        else if (is_safe_const_expression(v1)) {
            print_auto_only_one(v2); // 오직 한줄만 자동으로 answer 출력
        }
        // 2번만 모순없는 상수 식
        else if (is_safe_const_expression(v2)) {
            print_auto_only_one(v1); // 오직 한줄만 자동으로 answer 출력
        }
        // 1번 식의 x값과 2번식의 x값이 바로 나오는 경우
        else if (is_x_only_exist(v1) && is_x_only_exist(v2)) {
            string x1 = get_irreducible_fraction(v1[0],v1[2]);
            string x2 = get_irreducible_fraction(v2[0],v2[2]);
            if (x1 != x2) {
                print_answer(error,error);
            } else {
                print_answer(x1,error);
            }
        } else if (is_y_only_exist(v1) && is_y_only_exist(v2)) { // 1번 식의 y값과 2번식의 y값이 바로 나오는 경우
            string y1 = get_irreducible_fraction(v1[1],v1[2]);
            string y2 = get_irreducible_fraction(v2[1],v2[2]);
            if (y1 != y2) {
                print_answer(error,error);
            } else {// x값은 알 수 없음
                print_answer(error,y1);
            }
        }
        // 1번 값의 x는 나오고 2번 값은 y가 나오는 경우
        else if (is_x_only_exist(v1) && is_y_only_exist(v2)) {
            string x = get_irreducible_fraction(v1[0],v1[2]);
            string y = get_irreducible_fraction(v2[1],v2[2]);
            print_answer(x,y);
        }
            // 1번 값의 y는 나오고 2번 값은 x가 나오는 경우
        else if (is_y_only_exist(v1) && is_x_only_exist(v2)) {
            string y = get_irreducible_fraction(v1[1],v1[2]);
            string x = get_irreducible_fraction(v2[0],v2[2]);
            print_answer(x,y);
        }
            // 1번 x만존재 2번 둘다 존재
        else if (is_x_only_exist(v1) && is_xy_exist(v2)) {
            string x = get_irreducible_fraction(v1[0],v1[2]);
            /* 예시
            x=10/3;
            (2,4,3); // 2x+4y = 3`
            6,12,9; */
            int denom = get_denominator(x); // 분모
            int numer = get_numerator(x); // 분자
            multiply_vector(v2,denom); // 분모만큼 곱해주기
            v2[2] = v2[2] - multiply_fraction(denom,numer,v2[0]); // x에다가 곱하기
            v2[0] = 0; // x는 제거
            string y = get_irreducible_fraction(v2[1],v2[2]);// y구하기
            print_answer(x,y);
        }
            // 1번 y만존재 2번 둘다 존재
        else if (is_y_only_exist(v1) && is_xy_exist(v2)) {
            string y = get_irreducible_fraction(v1[1],v1[2]);
            int denom = get_denominator(y); // 분모
            int numer = get_numerator(y); // 분자
            multiply_vector(v2,denom); // 분모만큼 곱해주기
            v2[2] = v2[2] - multiply_fraction(denom,numer,v2[1]); // y에다가 곱하기
            v2[1] = 0; // y는 제거
            string x = get_irreducible_fraction(v2[0],v2[2]);// x구하기
            print_answer(x,y);
        }
            // 1번 둘다 존재  2번 x존재
        else if (is_xy_exist(v1) && is_x_only_exist(v2)) {
            string x = get_irreducible_fraction(v2[0],v2[2]);
            int denom = get_denominator(x); // 분모
            int numer = get_numerator(x); // 분자
            multiply_vector(v1,denom); // 분모만큼 곱해주기
            v1[2] = v1[2] - multiply_fraction(denom,numer,v1[0]);
            v1[0] = 0;
            string y = get_irreducible_fraction(v1[1],v1[2]);
            print_answer(x,y);
        }
            // 1번 둘다 존재 2번 y존재
        else if (is_xy_exist(v1) && is_y_only_exist(v2)) {
            string y = get_irreducible_fraction(v2[1],v2[2]);
            int denom = get_denominator(y); // 분모
            int numer = get_numerator(y); // 분자
            multiply_vector(v1,denom); // 분모만큼 곱해주기
            v1[2] = v1[2] - multiply_fraction(denom,numer,v1[1]);
            v1[1] = 0;
            string x = get_irreducible_fraction(v1[0],v1[2]);
            print_answer(x,y);
        } else {
            /*
            모순이 가능한 경우
             1x + 2y = 4;
             2x + 4y = 8;
            */
            // 계수가 전부 같은 경우 (x+2y=3이랑 2x+4y=6인 경우도 모순임)
            if (is_all_same(v1,v2)) {
                print_answer(error, error);
            } else {
                vector<int> v1cp(v1);
                vector<int> v2cp(v2);
                int cross1 = v2cp[0];
                int cross2 = v1cp[0];
                multiply_vector(v1cp,cross1); // 두번째 식의 x
                multiply_vector(v2cp,cross2);
                vector<int> v3 = {v1cp[0]-v2cp[0],v1cp[1]-v2cp[1],v1cp[2]-v2cp[2]};
                string y = get_irreducible_fraction(v3[1],v3[2]);

                cross1 = v2[1];
                cross2 = v1[1];
                multiply_vector(v1,cross1); // 두번째 식의 y
                multiply_vector(v2,cross2);
                vector<int> v4 = {v1[0]-v2[0],v1[1]-v2[1],v1[2]-v2[2]};
                string x = get_irreducible_fraction(v4[0],v4[2]);
                print_answer(x,y);
            }
        }
        if (t_cnt > 0) {
            string tmp;
            getline(cin,tmp); // 한줄 무시
        }
    }
}

bool is_digit(const string& s) {
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            continue;
        } else {
            if (i == 0 && (s[0] == '-' || s[0] == '+')) {
                continue;
            } else return false;
        }
    }
    return true;
}

// x,y,상수 순으로 리턴
vector<int> get_all_number(const string &s) {
    int equal_idx = s.find(" = ");
    string left = s.substr(0, equal_idx);
    string right = s.substr(equal_idx + 3);
    int left_x = get_number(left, "x");
    int left_y = get_number(left, "y");
    int left_const = get_const(left);
    int right_x = get_number(right, "x");
    int right_y = get_number(right, "y");
    int right_const = get_const(right);
    int all_x = left_x-right_x;
    int all_y = left_y-right_y;
    int all_const = right_const-left_const; // x,y라아 반대 순서
    return vector<int>{all_x,all_y,all_const};
}


int get_const(const string& str) {
    stringstream ss(str);
    ss.str();
    string tmp;
    int put_minus = 1;
    int number = 0;
    while (getline(ss,tmp,' ')) {
        string& tok = tmp;
        int only_num;
        if (tok == "+" || tok == "-") {
            put_minus = tok == "+" ? 1 : -1; // 음수 곱할건지
        } else {
            if (is_digit(tok)) { // x,y같은게 포함되지 않은 숫자
                only_num = put_minus*stoi(tok);
                number += only_num;
            }
            put_minus = 1; // ex)  -3 - -2 + 6에서 계산처리 했으면 다시 양수가 되어야함
        }
    }
    return number;
}
//int get_const(const string& str) {
//    regex reg("(-?\\d+ |-?\\d+$| \\+ | - )"); // + , - , 맨마지막 숫자
//    auto it = sregex_token_iterator(str.begin(), str.end(), reg);
//    auto end = sregex_token_iterator();
//    int number = 0;
//    int put_minus = 1;
//    while (it != end) {
//        string tok = *it;
//        int only_num;
//        if (tok == " + " || tok == " - ") {
//            put_minus = tok == " + " ? 1 : -1; // 음수 곱할건지
//        } else {
//            if (isspace(tok.back())) { // 마지막 공백
//                tok = tok.substr(0,tok.size()-1);
//            }
//            only_num = put_minus*stoi(tok);
//            put_minus = 1; // ex)  -3 - -2 + 6에서 계산처리 했으면 다시 양수가 되어야함
//            number += only_num;
//        }
//        it++;
//    }
//    return number;
//}


int get_number(string &str, string want_xyz) {
    stringstream ss(str);
    ss.str();
    string tmp;
    string want_xyz_minus1 = "-"+want_xyz;
    string want_xyz_plus1 = "+"+want_xyz;
    int number = 0;
    int put_minus = 1;
    while (getline(ss,tmp,' ')) {
        string& tok = tmp;
        if (tok == "+" || tok == "-") {
            put_minus = tok == "+" ? 1 : -1; // 음수 곱할건지
            continue;
        } else if (tok == want_xyz) { // 계수가 생략 되어 있는 경우
            number += put_minus*1;
            put_minus = 1; // ex)  -3 - -2 + 6에서 계산처리 했으면 다시 양수가 되어야함
        } else if (tok == want_xyz_minus1) { // 계수가 생략 되어 있는 경우
            number += put_minus*(-1);
            put_minus = 1; // ex)  -3 - -2 + 6에서 계산처리 했으면 다시 양수가 되어야함
        } else if (tok == want_xyz_plus1) { // 계수가 생략 되어 있는 경우
            number += put_minus*1;
            put_minus = 1; // ex)  -3 - -2 + 6에서 계산처리 했으면 다시 양수가 되어야함
        } else if (tok.substr(tok.size()-1) == want_xyz) { // 3x처럼 원하는 것
            number += put_minus*(stoi(tok.substr(0,tok.size()-1)));
            put_minus = 1;
        } else {
            put_minus = 1; // ex)  -3 - -2 + 6에서 계산처리 했으면 다시 양수가 되어야함
        }
    }
    return number;
}

//int get_number(string &str, string want_xyz) {
////    -3x, +3x, -x, +x, << 왼쪽께 전부 맨 뒤로 올경우
//    이거 다시짜기;
//    regex reg("(-?\\d*"+want_xyz+"| \\+ | - )");
//    string want_xyz_minus1 = "-"+want_xyz;
//    auto it = sregex_token_iterator(str.begin(), str.end(), reg);
//    auto end = sregex_token_iterator();
//    int number = 0;
//    int put_minus = 1;
//    while (it != end) {
//        string tok = *it;
//        int only_num;
//        if (tok == " + " || tok == " - ") {
//            put_minus = tok == " + " ? 1 : -1; // 음수 곱할건지
//            it++;
//            continue;
//        } else if (tok == want_xyz) { // 계수가 생략 되어 있는 경우
//            only_num = put_minus*1;
//            put_minus = 1; // ex)  -3 - -2 + 6에서 계산처리 했으면 다시 양수가 되어야함
//        } else if (tok == want_xyz_minus1) { // 계수가 생략 되어 있는 경우
//            only_num = put_minus*(-1);
//            put_minus = 1; // ex)  -3 - -2 + 6에서 계산처리 했으면 다시 양수가 되어야함
//        } else {
//            only_num = put_minus*stoi(tok.substr(0, tok.size() - 1));
//            put_minus = 1; // ex)  -3 - -2 + 6에서 계산처리 했으면 다시 양수가 되어야함
//        }
//        number += only_num;
//        it++;
//    }
//    return number;
//}
