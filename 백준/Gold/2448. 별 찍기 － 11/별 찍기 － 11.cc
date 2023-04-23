#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;


void draw(vector<vector<char>>& v, int y, int x);

void make_triangle(vector<vector<char>>& v, int len, int y, int x) {
    if (len == 3) {
        draw(v, y, x);
        return;
    }

    make_triangle(v, len / 2, y, x);
    make_triangle(v, len / 2, y + len / 2, x - len / 2);
    make_triangle(v, len / 2, y + len / 2, x + len / 2);
}


void draw(vector<vector<char>>& v, int y, int x) {
    // 작은 삼각형
    v.at(y).at(x) = '*';
    v.at(y+1).at(x - 1) = '*';
    v.at(y+1).at(x + 1) = '*';
    for (int i = 0; i < 5; i++) {
        v.at(y + 2).at(x - 2 + i) = '*';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<char>> v(N,vector<char>(2*N-1,' '));

    make_triangle(v, N, 0, N - 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            cout << v.at(i).at(j);
        }
        cout << '\n';
    }

    return 0;
}