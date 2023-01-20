#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
    int N,tmp;
    cin >> N;
    int** arr = new int*[N];
    int* lineIndex = new int[N];
    fill_n(lineIndex, N, N - 1);
    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        max = INT_MIN;
        int maxIndex = -1;
        for (int j = 0; j < N; j++) {
            if (lineIndex[j] >= 0 && max < arr[lineIndex[j]][j]) {
                max = arr[lineIndex[j]][j];
                maxIndex = j;
            }
        }
        lineIndex[maxIndex] -= 1;
    }
    cout << max;
}