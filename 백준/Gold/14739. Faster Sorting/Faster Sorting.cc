#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <ranges>
// #include<bits/stdc++.h>
#include <limits>
typedef long long ll;
typedef long double ld;

using namespace std;

unordered_map<int,pair<int,int>> map;

pair<int,int> func(vector<int>& v, vector<int>& asc, vector<int>& desc, int minRun) {
    if (map.contains(minRun)) {
        return map[minRun];
    }
    int subArr = 0;
    int badElement = 0;
    int cur = 0; // 시작할 때 0번으로 시작하기 위함
    while (cur < v.size()) {
        subArr++;
        int mk = max(asc[cur],desc[cur]);
        if (mk >= minRun) {
            cur += mk;
        } else {
            // mk < minRun
            badElement += (minRun-mk);
            cur += minRun;
            // index out of bounds
            if (cur >= v.size()) {
                badElement -= cur-v.size();
                break;
            }
        }
    }
    map[minRun] = {subArr,badElement};
    return {subArr,badElement};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    int Q;
    cin >> Q;
    vector<int> asc(N);
    vector<int> desc(N);


    // make asc
    int start = 0; // 증가의 시작인덱스
    for (int i = 1; i <= N; ++i) {
        // 감소하기 시작하는 경우나 마지막 인덱스의 경우?
        if (i==N || v[i] < v[i-1]) {
            // for문으로이전인덱스들채우기
            int acc = 1;
            for (int j = i-1; j>=start; j--) {
                asc[j] = acc;
                acc++;
            }
            start = i;
        } else {
            // 아직 증가하거나 같은 경우
        }
    }

    start = 0;
    for (int i = 1; i <= N; ++i) {
        // 증가하거나 같은 경우 마지막 인덱스의 경우?
        if (i==N || v[i] >= v[i-1]) {
            // for문으로이전인덱스들채우기
            int acc = 1; // 증가와 다르게 0부터 시작
            for (int j = i-1; j>=start; j--) {
                desc[j] = acc;
                acc++;
            }
            start = i;
        } else {
            // 아직 감소하는 경우
        }
    }

    // cout << "asc : ";
    // for (int i=0;i<N;i++) cout << asc[i] << " ";
    // cout << "\ndesc : ";
    // for (int i=0;i<N;i++) cout << desc[i] << " ";
    // cout << "\n";

    for (int i = 0; i < Q; ++i) {
        int q;
        cin >> q;
        auto [a1,a2] = func(v,asc,desc,q);
        cout << a1 << " " << a2 << "\n";
    }
}