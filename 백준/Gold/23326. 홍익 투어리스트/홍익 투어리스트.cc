#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	cin.tie(0);
	int N,Q;
	cin >> N >> Q;
	
	set<int> s;
	for (int i = 1; i<=N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 1) {
			s.insert(i); // 명소인 구역번호 삽입 (1부터 시작)
		}
	}

	int currentPos = 1; // 시작점은 1번 위치

	for (int i =0; i<Q; i++) {
		int query;
		cin >> query;
		if (query == 1) {
			int ms;
			cin >> ms;  // 명소 지정관련 위치
			// 존재한다면
			if (s.find(ms) != s.end()) {
				s.erase(ms);
			} else { // 존재하지 않는다면 추가
				s.insert(ms);
			}
		} else if (query == 2) {
			int move;
			cin >> move; // 시계방향으로 얼만큼 이동할지값;
			currentPos += move;
			// 나머지 처리
			if (currentPos > N)  {
				currentPos = currentPos % N;
				if (currentPos == 0) currentPos = N;
			}
		} else if (query == 3) {
			// query값 :  시계방향 최소 몇칸 문제
			auto lowerBound = s.lower_bound(currentPos);
			// auto upBound = s.upper_bound(currentPos);
			// 없는 경우 -> tree set에서 가장 작은 값이 정답
			if (s.size() == 0) { // 명소가 없는 경우
				cout << "-1\n";
			} else if (lowerBound == s.end()) { // treeset중에 가장작은pos가정답;
				int smallest = *s.begin();
				int gap1 = N-currentPos; // 한바퀴 돌아서 0번까지 가기 위함
				int gap2 = smallest;
				if (gap1+gap2 >= N) {
					throw out_of_range("error");
				}
				cout << gap1+gap2 << "\n";
			} else {
				// 만약 더 크거나 같은게 존재하면, upperbound에서 나온 값의 차이값만큼 더 큼 (예를들어 3번에 위치했는데 )
				int lowerValue = *lowerBound;
				int gap = lowerValue - currentPos;
				cout << gap << "\n";
			}
		} else {
			throw out_of_range("error");
		}
	}
}