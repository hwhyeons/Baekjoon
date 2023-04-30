#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

unordered_set<int> primes;

bool finish;
// dfs : 최적의 경우에만 호출
void dfs(unordered_map<int,int>& mp,int num, int end, int depth) {
    mp[num] = depth;
    if (num == end) {
        finish = true;
        cout << depth << "\n";
        return;
    }
    int fc1 = num/1000;
    int fc2 = (num%1000)/100;
    int fc3 = (num%100)/10;
    int fc4 = num%10;

    // 첫번째 자리를 바꾸는 경우
    for (int f1 = 1; f1 <= 9; ++f1) {
        if (f1 == fc1) continue; // 같은 수
        int next = (f1*1000)+(num%1000);

        // 소수가 아닌 경우
        if (!primes.contains(next)) continue;

        // 이미 존재할 경우 비교
        if (mp.contains(next)) {
            int savedDepth = mp[next];
            if (savedDepth <= depth+1) continue; // 저장된 경우가 더 작은 경우
            else {
                dfs(mp,next,end,depth+1);
            }
        } else {
            dfs(mp,next,end,depth+1);
        }
    }

    // 두번째 자리를 바꾸는 경우
    for (int f2 = 0; f2 <= 9; ++f2) {
        if (f2 == fc2) continue; // 같은 수
        int next = 1000*fc1+100*f2+10*fc3+fc4;

        // 소수가 아닌 경우
        if (!primes.contains(next)) continue;

        // 이미 존재할 경우 비교
        if (mp.contains(next)) {
            int savedDepth = mp[next];
            if (savedDepth < depth) continue; // 저장된 경우가 더 작은 경우
            else {
                dfs(mp,next,end,depth+1);
            }
        } else {
            dfs(mp,next,end,depth+1);
        }
    }

    // 세번째 자리를 바꾸는 경우
    for (int f3 = 0; f3 <= 9; ++f3) {
        if (f3 == fc3) continue; // 같은 수
        int next = 1000*fc1+100*fc2+10*f3+fc4;

        // 소수가 아닌 경우
        if (!primes.contains(next)) continue;

        // 이미 존재할 경우 비교
        if (mp.contains(next)) {
            int savedDepth = mp[next];
            if (savedDepth < depth) continue; // 저장된 경우가 더 작은 경우
            else {
                dfs(mp,next,end,depth+1);
            }
        } else {
            dfs(mp,next,end,depth+1);
        }
    }

    // 네번째 자리를 바꾸는 경우
    for (int f4 = 1; f4 <= 9; f4+=2) {
        if (f4 == fc4) continue; // 같은 수
        int next = 1000*fc1+100*fc2+10*fc3+f4;

        // 소수가 아닌 경우
        if (!primes.contains(next)) continue;

        // 이미 존재할 경우 비교
        if (mp.contains(next)) {
            int savedDepth = mp[next];
            if (savedDepth < depth) continue; // 저장된 경우가 더 작은 경우
            else {
                dfs(mp,next,end,depth+1);
            }
        } else {
            dfs(mp,next,end,depth+1);
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
     * 1. 네자리 모든 소수 구해서 set에 넣기
     * 2. BFS -> 브루트포스
     */


    vector<bool> vst(10000,false);
    for (int i = 2; i <= 9999; ++i) {
        if (vst[i]) continue;
        if (i >= 1000) primes.insert(i);
        for (int j = 1; j*i <= 9999; ++j) {
            vst[i*j] = true;
        }
    }


    int tcnt;
    cin >> tcnt;
    while (tcnt--) {
        int start, end;
        cin >> start >> end;
        string ans_str = to_string(end);
        finish = false;
        queue<pair<string,int>> q; // {4자리수 / 깊이}
        unordered_map<string,int> vst;
        q.emplace(to_string(start),0);
        vst[to_string(start)] = 0;
        string answer = "Impossible";
        while (!q.empty()) {
            auto pair = q.front(); q.pop();
            string cur = pair.first;
            int curDepth = pair.second;
            if (cur == ans_str) {
                answer = to_string(curDepth);
                break;
            }

            // 이미 방문 (큐의 이전 원소에서)
            if (vst.contains(cur)) {
                if (vst[cur] < curDepth) continue;
            }


            // dig : 자리수
            for (int dig = 0; dig < 4; ++dig) {
                char origin = cur[dig];
                for (char i = '0'; i <= '9'; ++i) {
                    if (i == origin) continue; // 동일한 경우
                    cur[dig] = i;
                    if (dig == 0 && cur[dig] == '0') continue; // 맨 앞자리 0
                    // 소수인 경우
                    if (primes.contains(stoi(cur))) {
                        // 이미 계산 된 값
                        if (vst.contains(cur) && vst[cur] <= curDepth) continue;
                        vst[cur] = curDepth+1;
                        q.push({cur,curDepth+1});
                    }
                }
                cur[dig] = origin;
            }
        }
        cout << answer << "\n";
    }
}