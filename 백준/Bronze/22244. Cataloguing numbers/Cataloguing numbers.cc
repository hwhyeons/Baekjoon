#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;

void is_correct(string& s) {
    int day = stoi(s.substr(0, 2));
    int month = stoi(s.substr(2, 2));
    int year_before_parse = stoi(s.substr(4, 3));
    int year = 0 <= year_before_parse && year_before_parse <= 599 ? 2000 + year_before_parse : 1000 + year_before_parse;
    int group = stoi(s.substr(7, 1));
    int division_answer = stoi(s.substr(8, 1));
    int acc = 0;
    if (!(group == 1 || group == 6 || group == 9)) {
        cout << 0 << "\n";
        return;
    }
    if (month == 0 || month >= 13) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 0; i < 8; i++) {
        int tmp = stoi(s.substr(i, 1));
        int sqr = tmp * tmp;
        acc += sqr;
    }
    if (acc % 7 != division_answer) {
        cout << 0 << "\n";
        return;
    }
    if (month == 2) {
        if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) { // 윤년인 경우
            if (day == 0 || day >= 30) {
                cout << 0 << "\n";
                return;
            }
        }
        else { // 2월인데 윤년이 아닌 경우
            if (day == 0 || day >= 29) {
                cout << 0 << "\n";
                return;
            }
        }
    }
    else {
        // 2월이 아닌 경우
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day == 0 || day > 31) {
                cout << 0 << "\n";
                return;
            }
        }
        else {
            if (day == 0 || day > 30) {
                cout << 0 << "\n";
                return;
            }
        }
    }

    cout << 1 << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string line1,line2,line3;
    cin >> line1 >> line2 >> line3;
    is_correct(line1);
    is_correct(line2);
    is_correct(line3);
}