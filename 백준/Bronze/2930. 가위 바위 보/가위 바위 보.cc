#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int get(char c1, char c2) {
    if (c1 == c2) return 1;
    if (c1 == 'R') {
        if (c2 == 'S') return 2;
        else return 0;
    } else if (c1 == 'S') {
        if (c2 == 'P') return 2;
        else return 0;
    } else {
        if (c2 == 'R') return 2;
        else return 0;
    }
}



int getScore(int idx, string& s1, vector<string>& v) {
    int acc = 0;
    for (int i = 0; i < v.size(); ++i) {
        acc += get(s1.at(idx),v.at(i).at(idx));
    }
    return acc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r; cin >> r;
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int acc = 0;
    for (int i = 0; i < s.size(); ++i) {
        acc += getScore(i,s,v);
    }
    cout << acc << "\n";

    acc = 0;
    for (int i = 0; i < s.size(); ++i) {
        int acc1 = 0,acc2=0,acc3=0;
        for (int j = 0; j < v.size(); ++j) {
            acc1 += get('R',v.at(j).at(i));
        }
        for (int j = 0; j < v.size(); ++j) {
            acc2 += get('S',v.at(j).at(i));
        }
        for (int j = 0; j < v.size(); ++j) {
            acc3 += get('P',v.at(j).at(i));
        }
        int mxAcc = max(acc1, max(acc2,acc3));
        acc += mxAcc;
    }
    cout << acc;
}