#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <numeric>
#include <vector>
#include <set>
#include<bitset>
#include <map>
#include <vector>
#include <stack>
#include <ranges>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int keys[] = { 0x30, 0x31,0x32,0x33, 0x34, 0x35, 0x36,0x37, 0x38,0x39};
    int arrChar[] = {0x30^0x20, 0x31 ^ 0x20, 0x32 ^ 0x20, 0x33 ^ 0x20, 0x34 ^ 0x20, 0x35 ^ 0x20, 0x36 ^ 0x20, 0x37 ^ 0x20, 0x38 ^ 0x20, 0x39 ^ 0x20,  // 만약 공백이나 온점인 경우에 가능한 모든 조합
                        0x30^46, 0x31 ^ 46, 0x32 ^ 46, 0x33 ^ 46, 0x34 ^ 46, 0x35 ^ 46, 0x36 ^ 46, 0x37 ^ 46, 0x38 ^ 46, 0x39 ^ 46}; // 만약 공백이나 온점인 경우에 가능한 모든 조합
    for (size_t i = 0; i < N; i++) {
        int hexEnc;
        cin >> hex >> hexEnc;
        if (ranges::find(arrChar, hexEnc) != end(arrChar)) {
            cout << ".";
        }
        else {
            cout << "-";
        }
    }
}
