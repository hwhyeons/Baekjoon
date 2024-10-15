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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    unordered_map<int, int> cntDict;

    // 카운트 기록
    for (auto& value : arr) {
        if (cntDict.contains(value)) {
            cntDict[value] += 1;
        } else {
            cntDict[value] = 1;
        }
    }

    stack<pair<int,int>> fValueStack; // {인덱스 , F()}값이 들어가는 Stack
    vector<int> ngfArr(N);
    // 역순 순회
    for (int i = N - 1; i >= 0; i--) {
        int originValue = arr.at(i); // Ai의 값
        int fValue = cntDict[originValue]; // F값
        int ans = 0;
        while (1) {
            if (fValueStack.empty()) {
                ans = -1;
                fValueStack.push({ i,fValue });
                break;
            }
            auto [topIdx, topFValue]  = fValueStack.top();
            if (topFValue > fValue) {
                ans = arr.at(topIdx);
                fValueStack.push({ i,fValue });
                break;
            } else {
                fValueStack.pop();
                continue;
            }
        }
        int ngfValue = ans;
        ngfArr[i] = ngfValue;
    }

    // 정답 출력
    for (auto& val : ngfArr) {
        cout << val << " ";
    }
}