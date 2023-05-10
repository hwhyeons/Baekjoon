#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> v(2*n-1);
    // 첫줄
    for (int i = 0; i < n; ++i) {
        v.front().push_back('*');
    }
    for (int i = 0; i < 2*n-3; ++i) {
        v.front().push_back(' ');
    }
    for (int i = 0; i < n; ++i) {
        v.front().push_back('*');
    }
    v.front().push_back('\n');

    // 사이
    for (int i = 1; i <= n - 2; ++i) {
        for (int j = 0; j < i; ++j) {
            v.at(i).push_back(' ');
        }
        v.at(i).push_back('*');
        for (int j = i; j < i+n-2; ++j) {
            v.at(i).push_back(' ');
        }
        v.at(i).push_back('*');
        for (int j = 0; j < (2 * n - 3) - (2 * i); ++j) {
            v.at(i).push_back(' ');
        }
        v.at(i).push_back('*');
        for (int j = i; j < i+n-2; ++j) {
            v.at(i).push_back(' ');
        }
        v.at(i).push_back('*');
        v.at(i).push_back('\n');
    }
    // 중앙
    for (int i = 0; i <= n-2; ++i) {
        v.at(n-1).push_back(' ');
    }
    v.at(n-1).push_back('*');
    for (int i = 0; i < n-2; ++i) {
        v.at(n-1).push_back(' ');
    }
    v.at(n-1).push_back('*');
    for (int i = 0; i < n-2; ++i) {
        v.at(n-1).push_back(' ');
    }
    v.at(n-1).push_back('*');
    v.at(n-1).push_back('\n');


    // 대칭
    for (int i = n,r=0; i < v.size()-1; ++i,++r) {
        for (int j = 0; j < n-2-r; ++j) {
            v.at(i).push_back(' ');
        }
        v.at(i).push_back('*');
        for (int j = 0; j < n-2; ++j) {
            v.at(i).push_back(' ');
        }
        v.at(i).push_back('*');
        for (int j = 0; j < 2*r+1; ++j) {
            v.at(i).push_back(' ');
        }
        v.at(i).push_back('*');
        for (int j = 0; j < n-2; ++j) {
            v.at(i).push_back(' ');
        }
        v.at(i).push_back('*');
        v.at(i).push_back('\n');
    }

    // 마지막
    for (int i = 0; i < n; ++i) {
        v.back().push_back('*');
    }
    for (int i = 0; i < 2*n-3; ++i) {
        v.back().push_back(' ');
    }
    for (int i = 0; i < n; ++i) {
        v.back().push_back('*');
    }

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.at(i).size(); ++j) {
            cout << v.at(i).at(j);
        }
    }
}