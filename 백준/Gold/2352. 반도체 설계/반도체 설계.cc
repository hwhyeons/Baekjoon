#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
typedef long double ld;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i=0;i<N;i++) {
        cin >> v[i];
    }

    // 와이어의 우측포트 번호 추가
    vector<int> wires;
    for (int val : v) {
        // 아직 원소 없을 때 (첫번째 원소)
        if (wires.empty()) {
            wires.push_back(val);
            continue;
        }

        // 예를들어 마지막 와이어가 2->2인데, 3->6 전깃줄을 만나면 추가해주면 됨
        if (val > wires.back()) {
            wires.push_back(val);
            continue;
        }

        // 중간 위치를 찾기
        // 예를들어 2-2 / 3-6가 들어있는 상황에서 4-3을 만났을 때
        // 3보다 큰 것중에 "가장 작은 것"을 교체하면 됨

        int s = 0;
        int e = (int)(wires.size())-1;
        int minChangeIndex = e; // 큰 것중에 "가장 작은 것"

        while (s<=e) {
            int m = (s+e)/2;
            // 2-2를 찾았는데 지금 4-3이면, val=3, wires[m]=2
            // 교체할 위치가아님. 더 큰 것중에서 찾아야함
            if (val > wires[m]) {
                s=m+1;
            } else {
                // 교체할 위치후보이므로 후보로 갱신
                minChangeIndex = min(m,minChangeIndex);
                e=m-1;
            }
        }

        wires[minChangeIndex] = val;
    }
    cout << wires.size();

}