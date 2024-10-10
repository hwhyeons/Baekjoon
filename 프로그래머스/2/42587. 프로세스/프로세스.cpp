#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;

class Proc {
public:
    int important;
    int loc; // 불변값
    Proc(int important, const int loc) {
        this->important = important;
        this->loc = loc;
    };

};

struct compare {
    bool operator()(const Proc& p1, const Proc& p2) {
        return p1.important < p2.important;
    }
};

int solution(vector<int> priorities, int location) {
    vector<Proc> ps;
    for (size_t i = 0; i < priorities.size(); i++) {
        auto p = Proc(priorities[i], i);
        ps.push_back(p);
    }

    vector<int> answerVector(priorities.size());

    deque<Proc> d;
    priority_queue<Proc,vector<Proc>, compare> pq;
    
    // deque 및 우선순위 큐에 순서대로 먼저 추가
    for (const Proc& p : ps) {
        d.push_back(p);
        pq.push(p);
    }

    int curOrder = 1;
    while (!d.empty()) {
        const Proc& front = d.front();
        const Proc& best = pq.top();
        int frontLoc = front.loc;
        // 바로 소모 가능한 경우
        if (front.important >= best.important) {
            d.pop_front(); // 제거
            pq.pop(); // 제거
            answerVector[frontLoc] = curOrder;
            curOrder++;
            continue;
        }
        // 소모가 불가능한 경우 -> 다시 추가 (우선순위 큐는 건들 필요 X)
        d.pop_front();
        d.push_back(front);
    }
    return answerVector[location];
}