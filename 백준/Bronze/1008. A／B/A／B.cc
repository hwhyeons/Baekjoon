#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    double A, B;
    cin >> A;
    cin >> B;
    cout << fixed;
    cout.precision(9);
    cout << A / B;
    return 0;
}
