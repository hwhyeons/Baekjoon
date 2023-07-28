#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
using namespace std;

string rev(string s) {
    return string(s.rbegin(),s.rend());
}

string swt(string s){
    string new_s;
    for (char c : s) {
        if (c=='1') {
            new_s.append("0");
        } else new_s.append("1");
    }
    return new_s;
}

string make(int n){
    if (n==1) {
        return "0";
    }
    auto before =  make(n-1);
    return before+"0"+swt(rev(before));
}


int main() {
    cin.tie(0);
    int tcnt;
    cin >> tcnt;
    string al = make(20);
    for (int i = 1; i <= tcnt; i++)
    {
        int n;
        cin >> n;
        cout << "Case #"<< i << ": " << al[n-1] << "\n";
    }

    return 0;
}