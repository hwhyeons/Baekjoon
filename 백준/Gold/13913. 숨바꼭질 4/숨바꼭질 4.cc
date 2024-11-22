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

class Node {
public:
    int pos;
};

void printPath(Node lastNode, vector<int>& beforeNode) {
    int cur = lastNode.pos;
    vector<int> posList;
    while (1) {
        posList.push_back(cur);
        if (beforeNode[cur] == -1) {
            break;
        } else {
            cur = beforeNode[cur];
            continue;
        }
    }

    ranges::reverse(posList);
    cout << posList.size() - 1 << "\n";
    for (auto& i : posList) {
        cout << i << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    bool visit[100001] = { false, };
    vector<int> beforeNode(100001, -1);
    queue<Node> q;
    visit[N] = true;
    beforeNode[N] = -1;
    q.push({N});
    while (!q.empty()) {
        Node topNode = q.front();
        q.pop();
        if (topNode.pos == K) {
            printPath(topNode,beforeNode); // 경로 출력
            break;
        }
        int curPos = topNode.pos;
        int next1 = curPos + 1;
        int next2 = curPos - 1;
        int next3 = 2 * curPos;
        auto initList = { next1,next2,next3 };
        for (auto k : initList) {
            if (k >= 0 && k <= 100000 && !visit[k]) {
                visit[k] = true;
                beforeNode[k] = curPos;
                q.push({ k});
            }
        }
    }


}