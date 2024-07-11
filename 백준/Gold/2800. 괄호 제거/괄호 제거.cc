#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <numeric>
#include <vector>
#include <set>
#include <unordered_set>
#include<bitset>
#include <map>
#include <vector>
#include <stack>
#include <ranges>

using namespace std;

string line;

void dfs(unordered_set<int>& can, int depth, vector<pair<int, int>>& pairVector,vector<string>& answers) {
    // can : 후보 인덱스들
    if (depth >= pairVector.size()) {
        if (can.size() == 0) { // 하나도 안된 경우
            return;
        }
        
        // 정답 추가
        string answer_string = "";
        for (int idx = 0; idx < line.size(); idx++) {
            if (can.contains(idx)) continue;
            answer_string += line.at(idx);
        }
        answers.push_back(answer_string);
        return;
    }

    // 추가 하는 경우
    auto [p1, p2] = pairVector.at(depth);
    can.insert(p1);
    can.insert(p2);
    dfs(can, depth + 1, pairVector, answers);
    can.erase(p1);
    can.erase(p2);
    dfs(can, depth + 1, pairVector, answers);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    stack<int> is; // indexStack
    cin >> line;
    vector<pair<int, int>> v; // 인덱스 쌍 
    for (size_t i = 0; i < line.size(); i++)    {
        if (line.at(i) == '(') {
            is.push(i);
        }
        else if (line.at(i) == ')') {
            int topIdx = is.top();
            is.pop();
            v.emplace_back(topIdx,i);
        }
    }
    
    vector<string> answers;
    unordered_set<int> can;
    // i : 괄호 몇개 쌍을 지울 것인지 (ex : i==2면 idx 두쌍만 삭제)
    dfs(can, 0, v, answers);

    // 중복정답 제거 필요
    sort(answers.begin(), answers.end());
    string beforeAns = "";
    for (string s : answers) {
        if (beforeAns != s) {
            cout << s << "\n";
        }
        beforeAns = s;
    }
}
