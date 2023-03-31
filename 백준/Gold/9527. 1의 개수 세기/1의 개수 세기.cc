#include <bits/stdc++.h>
#include <ranges>

#define ll long long

using namespace std;

vector<ll> dp;

// assign 먼저
void calculate_dp() {
    dp[0] = 1;
    dp[1] = 4;
    for (int i = 2; i < dp.size(); ++i) {
        dp[i] = 2*dp[i-1]+(ll)powl(2,i);
    }
}

string get_bitset(ll number) {
    if (number == 0) return "0";
    else if (number == 1) return "1";
    bitset<1000> s(number);
    string str = s.to_string();
    int index = str.find("1"); // 첫번째 1의 위치
    return str.substr(index);
}

ll get_number(string& bitset) {
    int index = bitset.find("1"); // 첫번째 1의 위치
    if (index == string::npos) return 0LL;
    return stol(bitset.substr(index),0,2);
}


// 0이면 0리턴
ll get_count(ll num) {
    if (num == 0) return 0LL;
    else if (num == 1) return 1LL;
    string bits = get_bitset(num);
    int len = bits.size(); // 2이상 보장
    string substrBits = bits.substr(1);

    // 최상위 비트만 제거
    ll remove_first_bit = get_number(substrBits);
    return dp.at(len-2) + remove_first_bit + get_count(remove_first_bit) + 1;

//    vector<bool> removeSet(bits.begin()+1,bits.end());
//    return add_bitset(removeSet,get_count(num.substr(1,num.size()-1)));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n1,n2;
    cin >> n1 >>n2;
//    string bits1 = get_bitset(n1);
    string bits2 = get_bitset(n2);
    int len2 = bits2.size(); // 자리수
    dp.assign(len2,LLONG_MAX);
    calculate_dp(); // 최대 자리수까지 계산 (ex : 10진수 23이면 0b10111이므로 len2가 5가 되고 다섯자리의 dp배열 리턴)
    ll first = get_count(n2);
    ll second = get_count(n1-1);
    cout << first-second;
}

