#include <bits/stdc++.h>
#include <ranges>

typedef long long ll ;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    cin.ignore();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin,s);
        if (mp.contains(s)) {
            mp[s] +=1;
        } else {
            mp[s] = 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        string query;
        getline(cin,query);
        int idx1= query.find_first_of(" ");
        int idx2= query.find_last_of(" ");
        string subject = query.substr(0,idx1);
        string fruit = query.substr(idx1+1,idx2-idx1-1);
        string color = query.substr(idx2+1);
        vector<string> v_s;
        vector<string> v_f;
        vector<string> v_c;
        if (subject == "-") {
            v_s.push_back("kor");
            v_s.push_back("eng");
            v_s.push_back("math");
        } else {
            v_s.push_back(subject);
        }

        if (fruit == "-") {
            v_f.push_back("apple");
            v_f.push_back("pear");
            v_f.push_back("orange");
        } else {
            v_f.push_back(fruit);
        }

        if (color == "-") {
            v_c.push_back("red");
            v_c.push_back("blue");
            v_c.push_back("green");
        } else {
            v_c.push_back(color);
        }

        int ans = 0;
        for (string sub: v_s) {
            for (string fr: v_f) {
                for (string co: v_c) {
                    string fin = "";
                    fin.append(sub);
                    fin.append(" ");
                    fin.append(fr);
                    fin.append(" ");
                    fin.append(co);
                    if (mp.contains(fin)) {
                        ans += mp[fin];
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}