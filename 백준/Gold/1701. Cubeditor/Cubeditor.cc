#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
typedef long double ld;
using namespace std;


// 잘 알려진 소수를 이용
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;


// 해시값을 long long을 쓰는 이유 : 예를들어 (약 20억 * 26 등)
typedef ll Hash; // 해시값

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >> text;
    // 길이를 기준으로 매개변수 탐색
    int s = 0;
    int e = text.size()-1;
    const int n = text.size();
    int answer = 0;
    while (s<=e) {

        // 길이 m을 기준으로 모두 슬라이싱
        int m = (s+e)/2;

        // 문제에서 원하는대로 동일한 부분문자열을 발견한 경우
        bool found = false;

        // 해시셋이 하나면 충돌 가능성이 매우 높으므로 두개의 해시를 통해 둘다 점검
        unordered_set<Hash> set1; // 1번 해시를 위한 집합
        unordered_set<Hash> set2; // 2번 해시를 위한 집합

        // 초기 0번인덱스부터 m크기의 블럭에 대한 해시값들의 합은 구해놓고 그 다음부터는 슬라이딩 윈도우처럼 빠질거는 빼고 새로 들어올거는 더하면 됨
        // 초기 해시값이 0이면 첫번째 인덱스에서 26^0*(char값)이 "0 + char값"="1*char값"이 되므로 자연스럽게 진행 가능
        // 물론 직관적으로는 초기 해시값은 26^0은 1이니깐 1로 해야하는거 아닌가 싶을 수 있는데 좀더 깔끔하게 구조를 작성하려면 0으로 해놓는게 쉬움
        Hash hash1 = 0;
        Hash hash2 = 0;
        Hash p1 = 1; // 예를들어 12345라는 문자열에서 "123"->"234"로 이동할때, 123에서 100을 빼야함. 즉 이건 최종적으로 고정임
        Hash p2 = 1;
        for (int i=0;i<m;i++) {
            char curChar = text[i];
            // abc에서 a는 'a'*26^0, b는 'b'*26^1, c는 'c'*26^2...
            int charValue = curChar-'a';
            hash1 = (charValue+(26*hash1)%MOD1)%MOD1;
            hash2 = (charValue+(26*hash2)%MOD2)%MOD2;

            // 여기서 i=m-1일 때는 곱을 안하는 이유
            //  => 쉽게 이해하기 위해 26진법말고 10진법이라고 가정하면,
            //  => m=3(블럭크기)인 예시에서 123에서 234로 슬라이딩 우측으로 가려면, 123에서 10^3이 아닌 10^2를 빼야하기 때문
            if (i < m-1) {
                p1 = (p1*26)%MOD1;
                p2 = (p2*26)%MOD2;
            }
        }

        // !! 맨 처음 초기값 해시셋에 넣어주는거 잊지말기
        set1.insert(hash1);
        set2.insert(hash2);


        // 초기 해시값을 구했으니 슬라이딩 윈도우처럼 진행하면 됨
        // i : 슬라이딩 윈도우의 왼쪽 (뺄 해시값)
        // i+m : 슬라이딩 윈도우의 오른쪽 (새로 더할 해시값)
        for (int i=0; i+m<n;i++) {
            int leftCharValue = text[i]-'a';
            int rightCharValue = text[i+m]-'a';
            // 슬라이드의 가장 왼쪽의 해시값은 빼준다
            // !! 이때 음수가 나올 수 있으므로 더해줘야함
            // 왜 음수가나오냐면, 만약에 저 값들이 모듈러 값을 안넘어가면 안나옴.
            // 하지만 모듈러에 의해 값이 축소되는 경우에는 hash보다 leftCharValue*p이 넘어갈 수 있음
            hash1 = ((hash1-leftCharValue*p1)%MOD1+MOD1)%MOD1;
            hash2 = ((hash2-leftCharValue*p2)%MOD2+MOD2)%MOD2;

            // 슬라이드의 가장 오른쪽 해시값은 더해준다
            // 예를들어 123에서 234로 넘어갈 때, 위 과정에서 -100은 해줬으니 23이 된 상태
            // 이제 23에서 230으로 만들어주기 위해 10을 곱하고 (!!26진법이라면 26을 곱하면 됨) 4를 더해준다
            hash1 = (hash1*26+rightCharValue)%MOD1;
            hash2 = (hash2*26+rightCharValue)%MOD2;

            // 슬라이딩을 마친 해시값이 둘다 있으면 충돌을 배제하고 새로운 정답을 발견했다고 가정
            if (set1.contains(hash1) && set2.contains(hash2)) {
                answer = max(answer, m); // 길이가 m인 블럭이므로
                found = true;
                break; // 어차피 이 for문 안쪽에서는 그 이후에 정답이 나와도 answer=m이므로, 굳이 더 진행 안해도 됨 (break안해도 문제 자체는 없음)
            } else {
                set1.insert(hash1);
                set2.insert(hash2);
            }
        }

        // 정답 후보를 찾은 경우
        // 문제에서 최대값을 구하는게 목표이므로, 매개변수 값을 좀더 크게 해서 탐방 해보면 됨
        if (found) {
            s = m+1;
        } else {
            e = m-1;
        }
    }
    if (answer == 1) answer=0;
    cout << answer;


}