#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;


unordered_set<int> s;


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int arr[100][100];
    for_each(arr,arr+100,[](int ar[]){
        fill_n(ar,100,0);
    });

    cin >> n;
    int i = 0;
    while (i++ < n) {
        int a,b;
        cin >> a >> b;
        int tmp = 0;
        for (int h = b; h < b+10; h++) {
            for (int w = a; w < a+10; w++) {
                arr[h][w] = 1;
                tmp++;
            }
        }
    }
    int cnt = 0;
    for (int j = 0; j < 100; j++)
    {
        for (int k = 0; k < 100; k++)
        {
            if (arr[j][k] == 1)
                cnt++;
        }
    }
    cout << cnt << "\n";
}
