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

typedef long long ll;
using namespace std;

// -----------------------------------------
// -----------------------------------------
// -----------------------------------------


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    const int s = N * N;
    vector<int> arr(s);
    for (size_t i = 0; i < s; i++) {
        cin >> arr[i];
    }
    nth_element(arr.begin(), arr.begin() + N -1 , arr.begin() + s,std::greater<int>());
    cout << arr.at(N-1);





}