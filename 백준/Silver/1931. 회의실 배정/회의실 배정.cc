#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <map>

#define ll long long

using namespace std;


class meeting{
public:
    int s,e;
    meeting(int s, int e) : s(s),e(e) {};
};

bool compare(meeting &m1, meeting &m2) {
    if (m1.e != m2.e) {
        return m1.e < m2.e;
    } else {
        return m1.s < m2.s;
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<meeting> v;

    for (int i = 0; i < n; i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        v.emplace_back(t1,t2);
    }

    ranges::sort(v,compare);

    int time = v[0].e;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (time <= v[i].s ) {
            time = v[i].e;
            cnt++;
        }
    }
    cout << cnt;
}
