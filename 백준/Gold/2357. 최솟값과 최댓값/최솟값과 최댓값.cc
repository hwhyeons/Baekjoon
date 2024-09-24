// 제곱근 분할 이용한 풀이 (세그먼트 트리 X)
#include <cmath>
#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>

typedef long long ll;
using namespace std;


int bucketSize;
int bucketCnt;
vector<pair<ll, ll>> buckets;
vector<ll> v;


ll findBest(int s, int e, bool wantMin) {
    int sGroup = s/bucketSize;
    int eGroup = e/bucketSize;

    // 같은 그룹 -> for문
    if (sGroup == eGroup) {
        if (wantMin) {
            return *min_element(v.begin() + s, v.begin() + e + 1);
        } else {
            return *max_element(v.begin() + s, v.begin() + e + 1);
        }
    }

    // 다른 그룹 -> 이전 그룹은 그룹 인덱스만큼만 수정하면 됨
    int sGroupEndPoint = (sGroup+1)*bucketSize - 1;
    int eGroupStartPoint = (eGroup) * bucketSize;
    ll innerMinMax = wantMin ? 2200000000 : -1;
    for (size_t i = sGroup+1; i < eGroup; i++) {
        auto& curBucket = buckets[i];
        ll minMax = wantMin ? curBucket.first : curBucket.second;
        innerMinMax = wantMin ? min(innerMinMax, minMax) : max(innerMinMax, minMax);
    }
    ll sGroupRenew = findBest(s, sGroupEndPoint, wantMin);
    ll eGroupRenew = findBest(eGroupStartPoint, e, wantMin);
    return wantMin ? min(sGroupRenew, min(eGroupRenew, innerMinMax)) : max(sGroupRenew, max(eGroupRenew, innerMinMax));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    v.assign(N,0);
    bucketSize = (int)(sqrt(N));
    bucketCnt = N / bucketSize + 1;
    buckets.assign(bucketCnt, { 2200000000LL ,-1 });
    // vector<pair<ll, ll>> buckets(bucketCnt, { 2200000000LL ,-1}); // pair : {최소,최대}
    for (size_t i = 0; i < N; i++) {
        cin >> v[i];
    }

    // best 저장
    for (size_t i = 0; i < N; i++) {
        int bucketNumber = i / bucketSize;
        auto& curBucket = buckets[bucketNumber];
        ll minVal = min(curBucket.first, v[i]);
        ll maxVal = max(curBucket.second, v[i]);
        buckets[bucketNumber] = { minVal,maxVal };
    }

    for (size_t i = 0; i < M; i++) {
        int queryA, queryB;
        cin >> queryA >> queryB;
        // 최소
        cout << findBest(queryA-1, queryB-1,true) << " ";
        // 최대
        cout << findBest(queryA - 1, queryB - 1, false)  << "\n";
    }
}