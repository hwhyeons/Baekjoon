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

int A, B, C;

bool is_close_to_0(double num) {
    return abs(num) < 0.0000000001;
}

double f(double x) {
    return A * x + B * sin(x) - C;
}


double f_prime(double num) {
    return A + B * cos(num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B >> C;
    double start = 0.0;
    double end = 300000.0;
    while (1) {
        double mid = (start + end) / 2;
        double y = f(mid);
        if (is_close_to_0(y)) {
            cout << fixed << setprecision(10);
            cout << mid;
            exit(0);
        }
        if (y > 0) {
            end = mid;
        }
        else { // y < 0
            start = mid;
        }
        continue;
    }


}