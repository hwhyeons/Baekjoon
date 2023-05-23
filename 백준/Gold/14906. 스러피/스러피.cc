#include <bits/stdc++.h>

using namespace std;
bool isSlump();

char c;
bool isSlimp() {
    c = getchar();
    if (c != 'A') return false;
    c = getchar();
    if (c == 'H') return true;
    if (c == 'B') {
        bool ok = isSlimp();
        if (!ok) return false;
        c = getchar();
        if (c!='C') return false;
        else return true;
    } else {
        ungetc(c,stdin);
        bool ok = isSlump();
        if (!ok) return false;
        c = getchar();
        if (c == 'C') return true;
        else return false;
    }
}

bool isSlump() {
    c = getchar();
    if (!(c == 'D' || c == 'E')) return false;
    c = getchar();
    if (c != 'F') return false;
    while (true) {
        c = getchar();
        if (c != 'F') break;
    }
    if (c == 'G') return true;
    else {
        ungetc(c,stdin);
        return isSlump();
    }
}

int main() {
    cin.tie(nullptr);
    int n;
    std::cin >> n;
    string answer("SLURPYS OUTPUT\n");
    getchar(); // 공백문자 한번 제거
    while (n--) {
        bool ok2 = isSlimp();
        bool ok1 = isSlump();
        if (ok1 && ok2) {
            c = getchar();
            if (c != '\n') { // 이미 끝났는데 뒤에 문자열 더 붙어있는 경우
                ungetc(c,stdin);
                answer.append("NO\n");
            } else {
                answer.append("YES\n");
            }
        } else {
            answer.append("NO\n");
        }
        while (true) {
            if (c == '\n') break;
            if (c == EOF) break;
            c = getchar();
            continue;
        }
    }
    answer.append("END OF OUTPUT");
    cout << answer;
    return 0;
}