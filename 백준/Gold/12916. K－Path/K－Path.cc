#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;
typedef long double ld;
using namespace std;

const ll MOD = 1000000007ll;
int N;
ll K;
vector<vector<ll>> composite(const vector<vector<ll>>& f1, const vector<vector<ll>>& f2) {
    // f1∘f2를 의미

    // f2의 모든 좌표에서 0값이 아닌걸 f1의 정의역에 대입해서 결과로
    vector<vector<ll>> output(N,vector<ll>(N));
    for (int r=0;r<N;r++) {
        for (int c=0;c<N;c++) {
            // 예를들어 r=2
            // f2에서 2번마을에서 3,4번 마을로 간다면 output에 f(3)의 결과와 f(4)의 결과를 합산 (단, 곱계수 적용)
            if (f2[r][c] ==0) continue;

            ll coeff = f2[r][c];
            // c번마을에서 다시 출발해야함
            for (int col=0;col<N;col++) {
                // c번마을에서 col번마을로 가는 경우
                output[r][col] += (coeff%MOD*f1[c][col]%MOD)%MOD; // 합성함수에서 정의역은 가장 처음 정의역을 유지해야함
                output[r][col]%=MOD;
            }
        }
    }
    return output;
}

// 5를 vector<bool> = {0,1,0,1}로
vector<bool> makeKtoBits(ll k) {
    vector<bool> bits;
    ll cur = k;
    while (true) {
        ll quotient = cur/2;
        ll div = cur%2;
        if (div==0) {
            bits.push_back(false);
        } else {
            bits.push_back(true);
        }
        if (quotient==0) break;
        cur = quotient;
    }
    reverse(bits.begin(),bits.end());
    return bits;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<vector<ll>> f1(N,vector<ll>(N));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> f1[i][j];
        }
    }

    // 기존 코드와 다르게, 개선 코드는 미리 f^{2^{30}}까지 합성함수를 미리 구해놓는게 아니라,
    // 비트열에서 1의 자리를 미리 구해서 최종 정답을 갱신할 때만 필요한 것을 누적하는 방식
    // -> K를 비트시프트로 1의 비트열만 정답에 갱신 (0자리도 계산은 다 해야됨. 그 이후에 계속 합성해야하니깐)
    // curAnswer의 시작을 항등함수(항등행렬)로 해놓으면 가장 처음 합성시에 그대로 나옴
    vector<vector<ll>> curAnswer(N,vector<ll>(N));
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (i==j) curAnswer[i][j] = 1; // 항등함수로 (자기자신으로 가는 경우)
        }
    }

    ll cur=1;
    vector<vector<ll>> currentMatrix = f1; // 현재 구해놓은 f^{2^n}
    // 0번비트열 = f^{2^1}은 이미 구했으므로 스킵
    for (int bitIdx=1; bitIdx<=30;bitIdx++) {
        // bitIdx번 비트열이 1인 경우 -> 결과에 누적
        if (cur & K) {
            curAnswer = composite(currentMatrix,curAnswer);
        }
        currentMatrix = composite(currentMatrix,currentMatrix); // ex) f^{2^4} = f^{2^2}∘f^{2^2}
        cur = cur << 1; // 왼쪽으로 밀기
    }

    // currentMatrix에 있는 모든 값 누적
    ll finalAnswer = 0ll;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            finalAnswer += curAnswer[i][j]%MOD;
            finalAnswer%=MOD;
        }
    }
    cout << finalAnswer;


    // // 이제 미리 필요한 것들을 구했으니 구하고자하는 K를 2의 제곱수의 합 형태로 분할해야함
    // vector<bool> bits = makeKtoBits(K);
    // // 5의 경우 bits는 {1,0,1}
    // // 따라서 합성할 때는 f^{2}∘f^{0}으로 합성을 진행하면 됨
    // // 인덱스는 역순으로 합성
    // assert(bits.size()<=31);
    // vector<vector<ll>> curAnswer;
    // for (int i=(int)(bits.size())-1,j=0;i>=0;i--,j++) {
    //     if (!bits[i]) continue;
    //     // 아직 합성된게 없는 경우
    //     if (curAnswer.empty()) {
    //         curAnswer = fList[j];
    //         continue;
    //     }
    //     // 합성 시작
    //     vector<vector<ll>> comp = composite(fList[j],curAnswer);
    //     curAnswer = comp;
    // }
    //
    // // curAnswer 순회해서 정답 누적
    // ll finalAnswer = 0ll;
    // for (int i=0;i<N;i++) {
    //     for (int j=0;j<N;j++) {
    //         finalAnswer += curAnswer[i][j]%MOD;
    //         finalAnswer%=MOD;
    //     }
    // }
    // cout << finalAnswer;
}