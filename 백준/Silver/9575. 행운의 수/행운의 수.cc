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

void combination(vector<int>& va, vector<int>& vb, vector<int>& vc, vector<int>& out, int depth) {
    if (depth == 3) {
        int acc = accumulate(out.begin(),out.end(),0);
        string str = to_string(acc);
        bool ok = all_of(str.begin(),str.end(),[](char c){
            if (c == '5' || c == '8') {
                return true;
            } else {
                return false;
            }
        });
        if (ok) s.insert(acc);
        return;
    }

    vector<int>* vtmp = nullptr;
    if (depth == 0) {
        vtmp = &va;        
    } else if (depth == 1) {
        vtmp = &vb;
    } else {
        vtmp = &vc;
    }

    for (int i = 0; i< vtmp->size(); i++) {
        out[depth] = vtmp->at(i);
        combination(va,vb,vc,out,depth+1);
    }
    return;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int testCase;
    cin >> testCase;
    for (int i =0; i<testCase; i++) {
        s.clear();
        int a_size,b_size,c_size;
        cin >> a_size;
        int j = 0;
        int t;
        vector<int> va,vb,vc;
        while (j++ < a_size) {
            cin >> t;
            va.push_back(t);
        }
        cin >>  b_size;
        j = 0;
        while (j++ < b_size) {
            cin >> t;
            vb.push_back(t);
        }
        j = 0;
        cin >> c_size;
        while (j++ < c_size) {
            cin >> t;
            vc.push_back(t);
        }

        vector<int> out(3);
        combination(va,vb,vc,out,0);

        cout << s.size() << "\n";
    }

    
}
