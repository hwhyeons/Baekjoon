#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>


using namespace std;

int main()
{
    string n1,n2;
    getline(cin, n1);
    getline(cin, n2);
    int n1_int = stoi(n1);
    char n2_char[4];
    int n2_arr[3];
    strcpy(n2_char, n2.c_str());
    for (int i = 0; i < 3; i++) {
        n2_arr[i] = n2_char[i] - 48;
    }
    string n2_str(n2_char);
    int n2_int = stoi(n2_str);
    cout << n1_int * n2_arr[2] << "\n";
    cout << n1_int * n2_arr[1] << "\n";
    cout << n1_int * n2_arr[0] << "\n";
    cout << n1_int * n2_int;
    return 0;
}
