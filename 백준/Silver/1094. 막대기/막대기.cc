#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
typedef long long ll;
using namespace std;

// -----------------------------------------
// -----------------------------------------
// -----------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int X; cin >> X;
    cout << ranges::count_if(bitset<8>(X).to_string(), [](char c) {return c == '1'; });
}