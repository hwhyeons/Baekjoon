#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;




// // great : "cur을" 우수마을로 할것인지
// // beforeGreat : 부모노드가 우수인지
// ll dfs(int cur, int great, int beforeNode, int beforeGreat) {
//     assert(great == 0 or great == 1);
//     if (dp[cur][great]) return dp[cur][great];
//     ll sum = 0ll;
//     ll allGreatSum = 0ll; // 모든 이웃 우수의 주민합
//     ll allNotGreatSum = 0ll; // 모든 이웃 비우수의 주민합
//     vector<tuple<int,ll,ll>> adjsValue; // {이웃번호, 우수일때_최대주민, 비우수_최대주민}
//     for (int adjNum : adjs[cur]) {
//         if (adjNum == beforeNode) continue; // 이웃노드가 부모 노드인경우
//         ll adjGreat = dfs(adjNum,1,cur,great);
//         ll adjNotGreat = dfs(adjNum,0,cur,great);
//         adjsValue.push_back({adjNum,adjGreat,adjNotGreat});
//         allGreatSum += adjGreat;
//         allNotGreatSum += adjNotGreat;
//     }
//
//     // 만약 자식이 없다면, 리프노드
//     if (adjsValue.empty()) {
//         // 우수 마을이라면 현재 마을의 주민 수, 비우수라면 0
//         return great ? v[cur] : 0ll;
//     }
//
//     // 우수마을인 경우 -> "아래"이웃들은 전부 비우수 + 나는 우수니깐 주민 수 세기
//     if (great) {
//         sum += allNotGreatSum + v[cur];
//     } else {
//         // 현재 마을이 비우수라면, 자식들중에 "적어도" 하나가 우수면 됨
//         int greatCnt = 0;
//         int notGreatCnt = 0;
//         // 일단 가장최고점으로 계산
//         ll bestAcc = 0ll;
//         for (auto& tp : adjsValue) {
//             auto [adjNum,accGreat,accNotGreat] = tp;
//             // 주의 : 최대한 우수가 확보되면 좋으므로 동등하다면 accGreat처리
//             if (accGreat >= accNotGreat) {
//                 greatCnt++;
//             } else {
//                 notGreatCnt++;
//             }
//             bestAcc += max(accGreat,accNotGreat);
//         }
//
//         // 가장 최적을 골랐는데 자식 중에 우수가 없는 경우
//         // 하지만 부모가 우수면 자식은 비우수여도 됨
//         if (greatCnt ==0 and !beforeGreat) {
//             // 합을 뺐을 때 가장 큰걸로
//             ll curBest = 0ll;
//             for (auto& tp : adjsValue) {
//                 auto [adjNum,accGreat,accNotGreat] = tp;
//                 assert(accNotGreat>=accGreat);
//                 curBest = max(curBest,bestAcc-accNotGreat+accGreat); // 하나만 강제로 우수마을로 교체
//             }
//             sum = curBest;
//         } else {
//             sum = bestAcc;
//         }
//     }
//     dp[cur][great] = sum;
//     return dp[cur][great];
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<ll> v(N+1);
    vector<vector<int>> nodes(10001,vector<int>()); // 인덱스:노드의깊이 / 값:노드번호
    vector<int> nodeDepthList(10001); // 노드번호에 따라 노드 깊이 출력
    vector<vector<int>> adjs; // (주민번호,이웃리스트)
    vector<vector<ll>> dp(10001,vector<ll>(3)); // (0:나는 비우수 자식들이 비우수 / 1:내가 우수 / 2:나는 비우수 자식들은 적어도 하나 우수)
    adjs.assign(N+1,vector<int>());
    for (int i=1;i<=N;i++) {
        cin >> v[i];
    }
    for (int i=0;i<N-1;i++) {
        int ta,tb;
        cin >> ta >> tb;
        adjs[ta].push_back(tb);
        adjs[tb].push_back(ta);
    }

    // bfs로 트리에 깊이를 부여
    queue<pair<int,int>> q; // {노드번호,깊이}
    vector<bool> visitTmp(10001,false);
    int maxDepth = 0;
    q.push({1,0}); // 1번 노드부터 깊이1
    while (!q.empty()) {
        int nodeNum = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (visitTmp[nodeNum]) continue;
        visitTmp[nodeNum] = true;
        nodes[depth].push_back(nodeNum);
        nodeDepthList[nodeNum] = depth;
        maxDepth = max(depth,maxDepth);
        for (int adj : adjs[nodeNum]) {
            q.push({adj,depth+1});
        }
    }
    assert(nodes[0].size()==1); // 루트노드는 한개

    // dp초기값 설정 : maxDepth
    for (int c=0; c<nodes[maxDepth].size(); c++) {
        int curNodeNumber = nodes[maxDepth][c];
        dp[curNodeNumber][0] = 0;
        dp[curNodeNumber][1] = v[curNodeNumber];
        dp[curNodeNumber][2] = 0;
    }

    // 낮은 깊이부터 순회
    for (int depth=maxDepth-1; depth>=0; depth--) {
        // c : depth에서의 노드 인덱스
        for (int c=0; c<nodes[depth].size(); c++) {
            int curNodeNumber = nodes[depth][c];
            const vector<int>& adjList = adjs[curNodeNumber]; // 현재 노드의 이웃 노드들

            // (0:나는 비우수 자식들은 상관없음 / 1:내가 우수 / 2:나는 비우수 자식들은 적어도 하나 우수(즉, 손자중에 하나는 우수)

            // 내가 비우수 + 자식들은 우수든 비우수든 상관 없는 경우
            // 그러려면 적어도 나도 비우수고 자식도 비우수고 손자도 비우수면 오류이므로, 손자는 우수임을 보장해얗마
            for (int adjNum : adjList) {
                if (nodeDepthList[adjNum]<=depth) continue; // 더 하위 노드일 수록 깊이가 큼 -> 따라서 이웃의 높이가 더 작다는건 부모 노드이므로 갱신 X (참조 문제)
                dp[curNodeNumber][0] += max(dp[adjNum][1],dp[adjNum][2]);
            }

            // 내가 우수한 마을이라면, 자식들은 0번조건or2번조건
            dp[curNodeNumber][1]+=v[curNodeNumber]; // 내가 우수한 마을이면 정답에 나의 마을 주민 수를 포함해야함
            for (int adjNum : adjList) {
                if (nodeDepthList[adjNum]<=depth) continue; // 더 하위 노드일 수록 깊이가 큼 -> 따라서 이웃의 높이가 더 작다는건 부모 노드이므로 갱신 X (참조 문제)
                dp[curNodeNumber][1] += max(dp[adjNum][0], dp[adjNum][2]);
            }

            // 내가 비우수지만 자식들은 적어도 한명은 비우수가 필요한 경우
            int childGreatCnt = 0; // 우수마을 자식 수
            int childNotGreatCnt = 0;
            for (int adjNum : adjList) {
                if (nodeDepthList[adjNum]<=depth) continue; // 더 하위 노드일 수록 깊이가 큼 -> 따라서 이웃의 높이가 더 작다는건 부모 노드이므로 갱신 X (참조 문제)
                if (dp[adjNum][1] >= dp[adjNum][0]) {
                    childGreatCnt++;
                } else {
                    childNotGreatCnt++;
                }
                dp[curNodeNumber][2] += max(dp[adjNum][1],dp[adjNum][0]);
            }
            // 최대 주민수 합을 구했지만 자식 중에서 비우수가 없는 경우
            ll curBest = dp[curNodeNumber][2];
            if (childGreatCnt == 0 && adjList.size()>=1) {
                for (int adjNum : adjList) {
                    dp[curNodeNumber][2] = max(dp[curNodeNumber][2], curBest-dp[adjNum][0]+dp[adjNum][1]); // adjNum을 우수한걸로 사용하는 경우
                }
            }
        }
    }

    // 루트노드가 1번 노드로 가정하므로
        cout << max(dp[1][0],max(dp[1][1],dp[1][2]));

}