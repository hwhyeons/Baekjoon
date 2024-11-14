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

class Num {
public:
    int idx;
    int val;
};

int N, L;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L;

    // 벡터에넣기->인덱스는1부터주의
    v.assign(N + 1, 0);
    for (size_t i = 1; i <= N; i++) cin >> v[i];

    deque <Num> d;
    for (int i = 1; i <= N; i++) {
        int leftIndex = i - L + 1;
        int rightIndex = i;
        
        // 인덱스 벗어나면 pop
        if (!d.empty() && d.front().idx < leftIndex) {
            d.pop_front();
        }

        // 아래값보다 큰 값들은 최소값에 영향을 안주기 때문에 삭제
        int removeValueOver = v.at(i);
        
        while (!d.empty()) {
            int backValue = d.back().val;
            if (backValue > removeValueOver) {
                d.pop_back();
                continue;
            } else {
                break;
            }
        }

        // 마지막 원소 추가
        d.push_back({ i,v.at(i) });
        cout << d.front().val << " ";
    }

}