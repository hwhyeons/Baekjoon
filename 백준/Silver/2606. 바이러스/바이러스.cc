#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

int answer = -1; // 첫 1번 컴퓨터는 제외
queue<int> q; // bfs용 큐

void bfs(vector<vector<int>>& v, vector<bool>& visited) {
	int pc_id = q.front();
	q.pop();
	if (visited[pc_id]) return;
	visited[pc_id] = true;
	answer++;
	for (int i = 0; i < v[pc_id].size(); i++) {
		if (visited[v[pc_id][i]]) continue;
		q.push(v[pc_id][i]);
	}
}

int main() {
	int pc_count,pair;
	scanf("%d\n%d", &pc_count, &pair);

	vector<vector<int>> v(pc_count+1); // 0번인덱스는 사용 X
	vector<bool> visited(pc_count + 1,false);
	for (int i = 0; i < pair;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// bfs
	q.push(1); // 1번 pc부터 감염 시작
	while (!q.empty()) {
		bfs(v, visited);
	}
	printf("%d",answer);
	return 0;
}
