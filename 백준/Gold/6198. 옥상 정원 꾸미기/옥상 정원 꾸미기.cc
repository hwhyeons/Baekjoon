#include <iostream>
#include <iomanip>
#include <ranges>
#include <stack>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ranges>
#include<deque>
// #include<bits/stdc++.h>
#include <limits>
typedef long long ll;
typedef long double ld;
using namespace std;


void printStack() {

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >>  N;
    vector<ll> answer(N);
    stack<tuple<int,int,int>> s; // (인덱스,숫자,누적)
    for (int ti=0; ti<N; ti++) {
        int cur;
        cin >> cur;

        // 만약 스택에 있다면 비교
        while (true) {
            if (s.empty()) {
                s.push({ti,cur,0});
                break;
            }
            auto[topIndex,topNum,topAcc] = s.top();
            if (cur >=topNum) {
                // (10,0) (3,0) 에서 7을 만난 경우
                // (3,0)은 빼고 정답처리
                answer[topIndex] = topAcc;
                s.pop();
                // top()원소에 누적값 갱신
                if (!s.empty()) {
                    auto[topIndex2,topNum2,topAcc2] = s.top();
                    s.pop();
                    s.push({topIndex2,topNum2,topAcc2+topAcc+1});
                }

                // (10,0)과 (7,0)을 비교하기 위해 넘어감
                continue;
            } else { // 탑이 10인데 3이 들어온 경우
                s.push({ti,cur,0});
                break;
            }
        }
    }

   //  남은스택처리
    while (!s.empty()) {
        auto[topIndex,topNum,topAcc] = s.top();
        answer[topIndex] = topAcc;
        s.pop();
        // top()원소에 누적값 갱신
        if (!s.empty()) {
            auto[topIndex2,topNum2,topAcc2] = s.top();
            s.pop();
            s.push({topIndex2,topNum2,topAcc2+topAcc+1});
        }
    }

    ll finalAnswer = 0;
    for (int i=0;i<N;i++) {
        finalAnswer+=(ll)answer[i];
    }

    cout<< finalAnswer;


}