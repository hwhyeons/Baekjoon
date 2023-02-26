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
#include <valarray>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    cin >> n;
    deque<int> dq(n);
    iota(dq.begin(),dq.end(),1);
    while (dq.size() != 1) {
        cout << dq.front() << " ";
        dq.pop_front();
        rotate(dq.begin(),dq.begin()+1,dq.end());
    }
    cout << dq.front();
    
}
