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


int MAX_VAL = 210000000;
int len = 0;
vector<int> v;

void swapRecursiveUp(int childIdx) {
    if (childIdx == 1) return;
    int parentIdx = childIdx / 2;
    int pVal = v[parentIdx];
    int cVal = v[childIdx];
    if (cVal < pVal) {
        swap(v[parentIdx], v[childIdx]);
        swapRecursiveUp(parentIdx);
    }
}
void addHeap(int newVal) {
    len++; // 3개 있으면 1,2,3번 인덱스에 들어있고 4번인덱스에 추가할 차례
    v[len] = newVal;
    swapRecursiveUp(len);
}

void swapRecursiveDown(int parentIndex) {
    int leftChildIndex = parentIndex*2;
    int rightChildIndex = leftChildIndex + 1;
    int parentValue = v[parentIndex];
    
    // 자식이 없는 경우 -> 교환하지 않아야하니, 최소힙 상황에서는 MAX_VAL로 설정해서 swap 일어나지 않게
    int lChildVal = leftChildIndex <= len ? v[leftChildIndex] : MAX_VAL;
    int rChildVal = rightChildIndex <= len ? v[rightChildIndex] : MAX_VAL;
    // 부모 노드가 가장 작은 경우 (최소힙)
    if (parentValue < lChildVal && parentValue < rChildVal) {
        return;
    }

    // 왼쪽 자식이 작은 경우
    if (lChildVal < rChildVal) {
        swap(v[leftChildIndex], v[parentIndex]);
        swapRecursiveDown(leftChildIndex);
    } else { // 오른쪽 자식이 작은 경우
        swap(v[rightChildIndex], v[parentIndex]);
        swapRecursiveDown(rightChildIndex);
    }
}

int popHeap() {
    int returnValue = v[1];
    swap(v[len], v[1]); // 맨마지막 원소를 맨 앞으로
    v[len] = 0; // 맨 마지막 원소 제거
    len--;

    // Down 방향으로 swap
    swapRecursiveDown(1);
    return returnValue;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    v.assign(N+1, 0);
    for (size_t i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        addHeap(tmp);
    }
    
    // test
    for (size_t i = 0; i < N; i++) {
        int val = popHeap();
        cout << val << "\n";
    }



}