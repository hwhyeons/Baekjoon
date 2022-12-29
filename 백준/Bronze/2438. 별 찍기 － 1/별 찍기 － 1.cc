#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>


using namespace std;

int main()
{
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
