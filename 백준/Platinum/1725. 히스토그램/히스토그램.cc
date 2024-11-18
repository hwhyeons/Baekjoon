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

bool debug = false;
int maxAnswer = 0;
class Block {
public:
    int height;
    int accWidth;


    int getAnswer() {
        return this->height * this->accWidth;
    }
};

    
void printStack(deque<Block>& s) {
    if (!debug) return;
    for (auto& i : s) {
        cout << "(" << i.height <<  " , " << i.accWidth << ") ";
    }
    cout << "\n";
}

// 원하는 숫자보다 크면 계속 빼서 누적

void accUntilNumber(deque<Block>& s, int wantStopHeight) {
    // 아예 빈 경우
    if (s.empty()) {
        s.push_back({ wantStopHeight,1 });
        printStack(s);
        return;
    }
    
    // 결합이 필요 없는 경우 (내림차순으로 안꺾이는 경우)
    if (s.back().height <= wantStopHeight) {
        s.push_back({ wantStopHeight,1 });
        printStack(s);
        return;
    }

    // 결합이 필요한 경우
    
    // 1-1 : d[-2]가 존재하지 않거나, d[-2] <= want_height라면 d[-1]과 want를 결합
    if (s.size() == 1 || s.at(s.size()-2).height <= wantStopHeight) {
        Block topBlock = s.back();
        s.pop_back();
        maxAnswer = max(maxAnswer, topBlock.getAnswer());
        s.push_back({ wantStopHeight, topBlock.accWidth + 1 });
        printStack(s);
        return;
    }

    // 1-2 : d[-2] > want_height라면 d[-2]와 d[-1]을 합침
    if (!(s.at(s.size() - 2).height > wantStopHeight)) throw "err";
    Block d1 = s.back();
    Block d2 = s.at(s.size() - 2);
    s.pop_back();
    maxAnswer = max(maxAnswer, d1.getAnswer());
    s.pop_back();
    maxAnswer = max(maxAnswer, d2.getAnswer());
    s.push_back({ d2.height,d1.accWidth + d2.accWidth });
    printStack(s);
    accUntilNumber(s,wantStopHeight); // 재귀호출
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    deque<Block> s;
    vector<int> v(N);
    for (size_t i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        int newHeight = v.at(i);
        if (debug) cout << "추가 예정 : " << newHeight << "\n";
        if (s.empty()) { // 스택에없는경우
            // 스택에_(높이, 1)추가;
            s.push_back({ newHeight,1 });
            printStack(s);
        } else if (newHeight >= s.back().height) { // 스택의 top보다 새로운 높이가 큰 경우
            // 높이는 cin값, 너비가 1인 값으로 스택에 추가
            s.push_back({ newHeight,1 });
            printStack(s);
        } else {
            // 스택의 top보다 새로운 높이가 미만인경우 (ex : {높:5,너:1}인데 새로운게 높이가 4인 경우
            // 기존 스택꺼 빼고 그 뺀 대상의 너비+1만큼 새로운 높이로 추가

            // 예 ) (1,2) (4,1) (5,1)에서 새 높이 1
            accUntilNumber(s, newHeight);
            //s.push_back({ newHeight,rt });
            printStack(s);
        }
    }

    if (debug) cout << "-----------------\n";
    while (!s.empty()) {
        Block topBlock = s.back();
        maxAnswer = max(maxAnswer, topBlock.getAnswer());
        s.pop_back();
        //printStack(s);
        // 이전 높이 누적
        if (!s.empty()) {
            Block& newTop = s.back();
            newTop.accWidth += topBlock.accWidth;
            printStack(s);
        }
    }
    cout << maxAnswer;

}