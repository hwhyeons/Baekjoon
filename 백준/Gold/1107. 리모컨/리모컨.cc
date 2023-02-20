#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int ans,mn,len_ans;
string ans_s;

void dfs(vector<int>& v, string current, vector<bool>& visit) {
	if (!current.empty()) {
		mn = min(mn,abs(stoi(current)-ans) + (int)(current.size()));
	}
	if (current.size() == len_ans+1) return;

	
	for (int i =0; i<v.size(); i++) {
		dfs(v,current+to_string(v[i]),visit);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> ans >> n;
	ans_s = to_string(ans);
	len_ans = ans_s.length();

	// 모든 버튼이 가능한 경우 : 10!은 너무 크기 때문에 이 경우에는, 두가지 경우만 비교하면 됨



	if (n == 0) {
		int k = to_string(ans).size(); // size()는 size_t 타입이라서 int로 변경 필요
		cout << min(abs(ans-100),k);
		return 0;
	} else if (n == 10) {
		cout << abs(ans-100);
		return 0;
	}
	

	vector<int> v(10);
	iota(v.begin(),v.end(),0);

	int t;
	for (int i =0;i<n;i++) {
		cin >> t;
		v.erase(find(v.begin(),v.end(),t));
	}

	sort(v.begin(),v.end());

	vector<bool> visit((int)v.size());
	
	// 순열로 모든 경우 테스트
	mn = abs(ans-100);
	dfs(v,"",visit);
	cout << mn;
}


