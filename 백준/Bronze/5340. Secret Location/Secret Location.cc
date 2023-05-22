#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> ans{"Latitude ","",":","",":","","\nLongitude ","",":","",":",""};
    for (int i = 0; i < 6; ++i)  {
        getline(cin,ans[2*i+1]);
        ans[2*i+1] = regex_replace(ans[2*i+1],regex(" +$"),"");
        ans[2*i+1] = to_string(ans[2*i+1].size());
    }
    copy(ans.begin(), ans.end(),ostream_iterator<string>(cout));
    return 0;
}