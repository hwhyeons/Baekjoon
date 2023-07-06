#include <bitset>
#include <deque>
#include <vector>
#include <iostream>


using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int cur = 0;
    vector<int> d;
    while (true) {
        if (cur == 0) {
            d.push_back(0);
        } else {
            bitset<100> bs(cur);
            string s = bs.to_string();
            int idx = s.find("1");
            for (int j =idx; j<s.size(); j++) {
                if (s[j] == '1') {
                    d.push_back(1);
                } else d.push_back(0);
            }
            if (d.size() >= n*5+10) {
                break;
            }
        }
        cur++;
    }
    k--;
    
    cout << d[k] << " " << d[n+k] << " " << d[2*n+k] << " " << d[3*n+k] << " " << d[4*n+k];
    return 0;
}   