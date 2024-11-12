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

int N, L;

vector<int> values;
//multiset<int> s;
//map<int,int> m;

class Element {
public:
    int value;
    int index;

    // 정렬기준: value는 작은게 앞, 인덱스도 작은게 앞(우선순위큐이므로 구현은 반대)
    bool operator<(const Element& other) const {
        if (this->value != other.value) {
            return this->value > other.value;
        }
        // 동일한 경우
        return this->index > other.index;
    }

};

// pq : value, index
priority_queue<Element> pq;

void push(int rightIdx) {
    if (rightIdx > 0) {
        int want = values.at(rightIdx);
        pq.push({want,rightIdx});
    }
}

/*
void pop(int leftIdx) {
    if (leftIdx > 0) {
        //auto it = s.find(values.at(leftIdx));
        
        
        //int beforeVal = m[values.at(leftIdx)];
        //if (beforeVal == 1) {
        //    m.erase(values.at(leftIdx));
        //} else {
        //    m[values.at(leftIdx)] -= 1;
        //}
    }
}
*/
void initPush(int leftIndex, int rightIndex) {
    for (int i = leftIndex; i <= rightIndex; i++) {
        if (i <= 0) continue;
        //int value = values.at(i);
        push(i);
        //s.insert(value);
    }
}

/*
int getAnswer() {
    //int left = i - L + 1;
    //int right = i;
    return (*m.begin()).first;
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cin >> N >> L;

    // 벡터에넣기->인덱스는1부터주의
    values.assign(N + 1, 0);
    for (size_t i = 1; i <= N; i++) {
        cin >> values[i];
    }
    
    // pushAndPopTreeSet();
    initPush(1-L+1,1); // 맨처음에는 multiset에 다 추가
    //cout << getAnswer() << " ";
    cout << pq.top().value << " ";
    for (int i = 2; i <= N; i++) {
        int leftIndex = i - L + 1;
        int rightIndex = i;
        auto rightNewOne = values.at(rightIndex);
        pq.push({ rightNewOne, rightIndex });
        while (!pq.empty()) {
            const Element& topElement = pq.top();
            if (topElement.index < leftIndex) {
                pq.pop();
                continue;
            }
            cout << pq.top().value << " ";
            break;
        }
        //pop(leftIndex - 1);
        //push(rightIndex);
        //cout << getAnswer() << " ";
    }
}