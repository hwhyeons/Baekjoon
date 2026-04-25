#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, p;
    cin >> s >> p;

    string cleanS = "";
    for (char c : s) {
        // 숫자가 아닌 경우(알파벳인 경우)에만 추가
        if (!(c >= '0' && c <= '9')) {
            cleanS += c;
        }
    }

    if (cleanS.find(p) != string::npos) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}