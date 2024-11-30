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
    int y;
    int x;
};
int starY1, starY2, starX1, starX2;

vector<Node> allNodes;

void moveStarY(int move) {
    starY2 += move;
    starY1 += move;
}

void moveStarX(int move) {
    starX2 += move;
    starX1 += move;
}

int getAnswer() {
    int ans = 0;
    for (Node& node : allNodes) {
        if (node.y <= starY2 && node.y >= starY1 && node.x <= starX2 && node.x >= starX1) ans++;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, L, K;
    cin >> N >> M >> L >> K;
    for (size_t i = 0; i < K; i++) {
        int t1, t2;
        cin >> t1 >> t2; // t1 = x , t2 = y
        allNodes.push_back({ t2,t1 });
    }

    //vector<Node> sortByY(allNodes);
    //vector<Node> sortByX(allNodes);
    /*sort(sortByX.begin(), sortByX.end(), [](Node& n1, Node& n2) {
            return n1.x < n2.x;
        });
    sort(sortByY.begin(), sortByY.end(), [](Node& n1, Node& n2) {
        return n1.y < n2.y;
        });*/
    //int minX = sortByX.front().x;
    //int maxX = sortByX.back().x;
    //int minY = sortByY.front().y;
    //int maxY = sortByY.back().y;
    int maxAnswer = 0;

    //starY1 = minY;
    //starY2 = minY + L;
    //starX1 = minX;
    //starX2 = minX + L;

    /*
    int rightX = 0;
    for (size_t i = 0; i < allNodes.size(); i++) {
        if (sortByX.at(i).x <= starX2) rightX = i;
        else break;
    }

    int endY = 0;
    for (size_t i = 0; i < allNodes.size(); i++) {
        if (sortByY.at(i).y <= starY2) endY = i;
        else break;
    }
    */
    
    for (size_t i = 0; i < K; i++) {
        for (size_t j = 0; j < K; j++) {
            Node first = allNodes[i];
            Node second = allNodes[j];
            starX1 = first.x;
            starX2 = starX1 + L;
            starY1 = second.y;
            starY2 = starY1 + L;
            maxAnswer = max(maxAnswer, getAnswer());
        }
    }
    cout << K - maxAnswer;

    /*
    for (int leftX = 0; leftX < allNodes.size(); ) {
        for (int startY = 0; startY < allNodes.size();) {
            int localAnswer = getAnswer();
            maxAnswer = max(localAnswer, maxAnswer);
            // endY를_늘릴_수_없다면_
            if (endY != allNodes.size() - 1) {
                int gapStartNew = sortByY.at(startY + 1).y - sortByY.at(startY).y;
                int gapStartEnd = sortByY.at(endY + 1).y - sortByY.at(endY).y;
                if (gapStartNew < gapStartEnd) {
                    moveStarY(gapStartNew); // 일정량 이동
                } else {
                    moveStarY(gapStartEnd); // 일정량 이동
                }
                if (sortByY.at(startY + 1).y >= starY1) startY++;
                if (sortByY.at(endY + 1).y <= starY2) endY++;
            } else {
                break;
            }
        }
        //int localAnswer = getAnswer();
        //maxAnswer = max(localAnswer, maxAnswer);
        //for (int startY = 0; startY < allNodes.size(); startY++) { 여기서늘리는거제거;
        bool tf_break_signal = false;
        if (rightX != allNodes.size() - 1) {
            int gapXLeft = sortByX.at(leftX + 1).x - sortByX.at(leftX).x;
            int gapXRight = sortByX.at(rightX + 1).x - sortByX.at(rightX).x;
            if (gapXLeft < gapXRight) {
                moveStarX(gapXLeft);
            } else {
                moveStarX(gapXRight);
            }
            //if (starX1 > sortByX.at(leftX + 1).x) leftX++;
            if (sortByX.at(leftX + 1).x >= starX1) leftX++;
            if (sortByX.at(rightX + 1).x <= starX2) rightX++;
        } else {
            tf_break_signal = true;
        }
        if (tf_break_signal) break;
    }
    */
    

}