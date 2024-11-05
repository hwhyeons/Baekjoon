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
// -----------------------------------------
// -----------------------------------------

// 오름차순 퀵정렬
void quickSort(vector<int>& v, const int left, const int right) {
    if (left >= right) return;
    const int pivotIndex = (left + right) / 2;
    int l = left;
    int r = right;
    const int pivotValue = v.at(pivotIndex);
    while (l <= r) {
        while (v.at(l) < pivotValue) { // l이 인덱스 벗어날 일이 없는 이유 : pivotValue랑 같아지는 순간도 반복문 종료
            l++;
        }
        while (v.at(r) > pivotValue) { // r이 인덱스 벗어날 일이 없는 이유 : pivotValue랑 같아지는 순간도 반복문 종료
            r--;
        }
        if (l <= r) {
            swap(v[l], v[r]);
            // 교환 한 후에는 다시 값 변환 필요. 안그러면 예를들어 1 4 3 4 5 4 7에서 가장왼쪽4가 l, 중간 4가 pivot, 오른쪽 4가 r이면 무한루프
            // 또한, l==r인상황에서 아래의 l++, r--를 안하면, 그 다음 바깥반복문 진행시에 위 두개의 while문에서 둘다 l,r값 변화가 없으므로 바깥 루프 무한반복
            l++;
            r--;
        }
    }
    //quickSort(v, left, pivotIndex);
    quickSort(v, left , r);
    //quickSort(v, pivotIndex+1, right);
    quickSort(v, l,right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v(N);
    for (size_t i = 0; i < N; i++)  cin >> v[i];
    quickSort(v, 0, v.size() - 1);
    for (auto& k : v) {
        cout << k << "\n";
    }
}