#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = -1;
    for (int i =0;i<n;i++)
    {
        vector<int> v(4);
        cin >> v[0] >> v[1] >> v[2] >> v[3];

        unordered_map<int,int> m;
        for (int i =0; i<4;i++) {
            int num = v[i];
            if (m.count(num)) {
                m[num] = m[num]+1;
            } else {
                m[num] = 1;
            }
        }
    
        int tmp = 0;
        if (m.size() == 4) { // 전부 다른 경우
            tmp = (*max_element(m.begin(),m.end())).first;
            tmp = tmp*100;
        } else if (m.size() == 3) { // 두개만 쌍이고 두개는 다른 경우
            tmp = (find_if(m.begin(),m.end(),[](auto key){
                if (key.second == 2) {
                    return true;
                } else return false;
            }))->first;
            tmp = 1000 + tmp*100;
        } else if(m.size() == 2) { // 두개 두개 or 세개 1개
            bool ok = all_of(m.begin(),m.end(),[](auto key) {
                if (key.second == 2) return true;
                else return false;
            });
            if (ok) { // 두개 and 두개
                tmp = 2000+500*(m.begin()->first) + 500*((++m.begin())->first);
            } else {
                if (m.begin()->second == 3) {
                    tmp = 10000+(m.begin()->first)*1000;
                } else {
                    auto tt = ++m.begin();
                    tmp = 10000+(tt->first)*1000;
                }
            }
        } else if (m.size() == 1) {
            tmp = 50000+(m.begin()->first)*5000;
        }
        ans = max(ans,tmp);
    }
    cout << ans;
    return 0;
}
