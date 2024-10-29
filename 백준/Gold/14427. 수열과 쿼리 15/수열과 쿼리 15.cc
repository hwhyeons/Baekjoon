#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;
// -----------------------------------------

class Element {
public:
    int value;
    const int idx;
    auto operator<=>(const Element& rhs) const = default;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> arr(N);
    set<Element> s;
    for (int i = 0; i < N; i++) { // size_t X (유니폼 초기화)
        cin >> arr[i];
        s.insert({ arr[i],i });
    }

    int M;
    cin >> M;
    for (size_t i = 0; i < M; i++) {
        int type;
        cin >> type;
        if (type == 2) {
            cout << (*s.begin()).idx+1 << "\n";
        } else {
            // assert type==1
            int idx, newVal;
            cin >> idx >> newVal;
            idx--; // 인덱스는 1부터 시작하는데 여기서는 0부터 시작
            int tmp = arr[idx];
            auto removeIter = s.find({ tmp,idx});
            if (removeIter == s.end()) throw "err";
            s.erase(removeIter);
            arr[idx] = newVal; // 새로운 값으로 갱신
            s.insert({ arr[idx],idx });
        }
    }

}