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


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    if (b == 1) {
        cout << a;
        return 0;
    }
    for (int i =b; i<1000000000; i++) {
        int divide = a/i;
        int mod = a%i;
        long long acc = divide;
        int cnt = 1;
        if (mod == 0) {
            for (int j =1; j<i/2+1;j++){
                acc += divide-j;
                cnt++;
                if (divide-j<0) {
                    cout << "-1";
                    return 0;
                }
            }
            for (int j =1; j<i/2+1;j++){
                if (divide+j >a) {
                    cout << "-1";
                    return 0;
                }
                acc += divide+j;
                cnt++;
            }
            if (cnt > 100) {
                cout << "-1";
                return 0;
            }
            if (acc == a) { // 정답
                if (cnt != i) {
                    cout << "-1";
                    return 0;
                }
                vector<int> v;
                for (int j =1; j<i/2+1;j++){
                    v.push_back(divide-j);
                }
                for (int j = v.size()-1; j>=0; j--) {
                    cout << v[j] << " ";
                }
                cout << divide << " ";
                for (int j =1; j<i/2+1;j++){
                    cout << divide+j << " ";
                }
                return 0;
            }
        } else {
            for (int j =1; j<i/2;j++){
                acc += divide-j;
                cnt++;
                if (divide-j<0) {
                    cout << "-1";
                    return 0;
                }
            }

            for (int j =1; j<i/2+1;j++){
                acc += divide+j;
                if (divide+j >a) {
                    cout << "-1";
                    return 0;
                }
                cnt++;
            }
            if (cnt > 100){
                cout << "-1";
                return 0;
            }
            if (acc == a) { // 정답
                if (cnt != i) {
                    cout << "-1";
                    return 0;
                }
                vector<int> v;
                for (int j =1; j<i/2;j++){
                    v.push_back(divide-j);
                }
                for (int j = v.size()-1; j>=0; j--) {
                    cout << v[j] << " ";
                }
                cout << divide << " ";
                for (int j =1; j<i/2+1;j++){
                    cout << divide+j << " ";
                }
                return 0;
            }
        }

    }
    cout << "-1";

}
