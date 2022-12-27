#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string a;
    string b;
    cin >> a;
    cin >> b;
    stringstream s(a);
    stringstream s2(b);
    int n1;
    int n2;
    s >> n1;
    s2 >> n2;
    cout << n1 + n2 << "\n";
    cout << n1 - n2 << "\n";
    cout << n1 * n2 << "\n";
    cout << n1 / n2 << "\n";
    cout << n1 % n2;
    return 0;
}