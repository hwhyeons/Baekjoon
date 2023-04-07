#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

void printError();

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    // 대문자 하나라도 포함
    bool is_java = any_of(s.begin(),s.end(),[](char c){
        return isupper(c);
    });
    bool is_cpp = any_of(s.begin(),s.end(),[](char c) {
        return c == '_';
    });
    if (!is_cpp && !is_java) { // 전부 소문자에 하이픈 없는 경우
        cout << s;
        return 0;
    }

    if (is_cpp && is_java) {
        printError();
        return 0;
    }
    else if (is_cpp && (s.front() == '_' || s.back() == '_')) {
        printError();
        return 0;
    } else if (is_java &&isupper(s.front())) {
        printError();
        return 0;
    }

    if (is_cpp) {
        regex pattern("_");
        auto it = sregex_token_iterator(s.begin(), s.end(),pattern,-1);
        auto end = sregex_token_iterator();
        bool flag = true;
        string f = "";
        while (it != end) {
            string str = *it;
            if (str == "") { // 하이픈이 두개 이상 들어가면 중간에 공백으로 잘려지므로 오류
                printError();
                return 0;
            }
            if (flag) {
                f.append(str);
                flag = false;
            } else {
                str[0] = toupper(str[0]);
                f.append(str);
            }
            it++;
        }
        cout << f;
    } else { // java to cpp
        string f = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isupper(s[i])) {
                f.append("_");
                f.append(string(1,tolower(s[i])));
            } else {
                f.append(string(1,s[i]));
            }
        }
        cout << f;
    }
}

void printError() { cout << "Error!"; }
