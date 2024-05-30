#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdexcept>
// #include <cassert>
// #include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int startIdx = 2000000000;
	int endIdx = 2000000000;
	int bestIndex = 2000000000;
	Node* parentNode = nullptr;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;

	// 최하위 노드인지 체크
	bool isEndNode() {
		// assert(startIdx != -1 && endIdx != -1);
		return startIdx == endIdx;
	}
};

vector<Node*> nodeVector;


// 처음 자식 노드 생성
Node* initChild(int leftIdx, int rightIdx, Node* parentNode) {
	if (parentNode != nullptr) {
		if (parentNode->startIdx == 2000000000 || parentNode->endIdx == 2000000000) throw invalid_argument("aaaa");
	}

	// 동일한 인덱스 -> 최하위 노드까지 도착 -> 부모 연결
	if (leftIdx == rightIdx) {
		nodeVector.at(leftIdx)->parentNode = parentNode;
		if (nodeVector.at(leftIdx) == nullptr) {
			throw invalid_argument("left nullptr");
		}
		return nodeVector.at(leftIdx);
	}

	Node* curNode = new Node;
	curNode->startIdx = leftIdx;
	curNode->endIdx = rightIdx;

	int midIdx = (leftIdx + rightIdx) / 2;
	Node* child1 = initChild(leftIdx, midIdx, curNode);
	curNode->leftChild = child1;
	Node* child2 = initChild(midIdx + 1, rightIdx, curNode);
	curNode->rightChild = child2;
	if (child1 != nullptr) {
		child1->parentNode = curNode;
	}
	if (child2 != nullptr) {
		child2->parentNode = curNode;
	}
	return curNode;
}


void initBestValue(Node* parentNode, vector<int>& v) {
	if (parentNode == nullptr) {
		return;
	}

	// 최하위 노드
	if (parentNode->startIdx == parentNode->endIdx) {
		if (parentNode->bestIndex == 2000000000) throw invalid_argument("err");
		return;
	}

	if (parentNode->leftChild == nullptr && parentNode->rightChild == nullptr) {
		throw invalid_argument("err2");
	}

	if (parentNode->leftChild == nullptr) {
		if (parentNode->rightChild->bestIndex == 2000000000) {
			initBestValue(parentNode->rightChild, v);
		}
		parentNode->bestIndex = (parentNode->rightChild)->bestIndex;
	}
	else if (parentNode->rightChild == nullptr) {
		if (parentNode->leftChild->bestIndex == 2000000000) {
			initBestValue(parentNode->leftChild, v);
		}
		parentNode->bestIndex = (parentNode->leftChild)->bestIndex;
	}
	else {
		if (parentNode->leftChild->bestIndex == 2000000000) {
			initBestValue(parentNode->leftChild, v);
		}
		if (parentNode->rightChild->bestIndex == 2000000000) {
			initBestValue(parentNode->rightChild, v);
		}
		int leftBest = (parentNode->leftChild)->bestIndex;
		int rightBest = (parentNode->rightChild)->bestIndex;
		if (v[leftBest] <= v[rightBest]) { // 등호가 들어가야 값이 같을 때 왼쪽 인덱스를 적용할 수 있음
			parentNode->bestIndex = leftBest;
		}
		else {
			parentNode->bestIndex = rightBest;
		}
	}

	// 자식 노드도 수행
	initBestValue(parentNode->leftChild, v);
	initBestValue(parentNode->rightChild, v);
}

Node* rootNode;

void makeSegmentTree(int N, vector<int>& v) {
	// 세그먼트 트리에 최하위 노드들 전부 추가
	for (int i = 1; i <= N; i++) {
		Node* node = new Node;
		node->startIdx = i;
		node->endIdx = i;
		node->bestIndex = i;
		nodeVector.push_back(node);
	}

	// 0번 인덱스에 빈 노드 추가
	rootNode = initChild(1, N, nullptr);
	

	// bestValue를 첫번째 초기화
	initBestValue(rootNode, v);

}


int findBestValue(Node* node, int checkStartIdx, int checkEndIdx, vector<int>& v) {
	if (node == nullptr) {
		return 2000000000;
	}

	if (node->startIdx == -1 || node->endIdx == -1) {
		throw 6;
	}

	if (checkEndIdx < node->startIdx || checkStartIdx > node->endIdx) {
		return 2000000000;
	}
	
	if (node->startIdx >= checkStartIdx && node->endIdx <= checkEndIdx) {
		return node->bestIndex;
	}
	

	// 최하단 노드인경우
	if (node->isEndNode()) {
		return node->bestIndex;
	}


	// 경계 벗어나면 자르기
	//checkStartIdx = max(checkStartIdx, node->startIdx);
	//checkEndIdx = min(checkEndIdx, node->endIdx);

	// assert(checkEndIdx != -1 && checkStartIdx != -1);

	// 찾고자 하는 값이 1~4인데 왼쪽노드가 4이상을 가진 경우
	/*
		if (node->leftChild != nullptr) {
		// if (node->leftChild->endIdx == checkEndIdx && node->leftChild->startIdx==checkStartIdx) {
		if (node->leftChild->endIdx >= checkEndIdx) {
			return findBestValue(node->leftChild, checkStartIdx, checkEndIdx, v);
		}
	}
	*/


	// 오른쪽에만 있는 경우
	/*
		if (node->rightChild != nullptr) {
		if (node->rightChild->startIdx <= checkStartIdx) {
			return findBestValue(node->rightChild, checkStartIdx, checkEndIdx, v);
		}
	}
	*/

	// 중간에 걸쳐진 경우 (예 : 왼쪽이 1~2고 오른쪽이 3~5인데 찾고자하는게 2~3사이의 최대)
	int leftBestIdx = findBestValue(node->leftChild, checkStartIdx, checkEndIdx, v);
	int rightBestIdx = findBestValue(node->rightChild, checkStartIdx, checkEndIdx, v);
	int leftBestValue = leftBestIdx == 2000000000 ? 2000000000 : v.at(leftBestIdx);
	int rightBestValue = rightBestIdx == 2000000000 ? 2000000000 : v.at(rightBestIdx);
	if (leftBestIdx == 2000000000 and rightBestIdx == 2000000000) throw 4;
	
	if (leftBestValue <= rightBestValue) {
		return leftBestIdx;
	}
	else {
		return rightBestIdx;
	}

}

void renewMinMax(Node* node, vector<int>& v) {
	// 최하단 노드의 경우 bestIndex는 고정
	/*
	if (node->isEndNode()) {
		if (node->parentNode != nullptr) {
			if (node->parentNode == node) throw 2;
			renewMinMax(node->parentNode, v);
		}
		return;
	}
	*/


	// 중간 또는 루트노드인경우
	if (node == nullptr) {
		return;
	}

	int left1 = node->leftChild == nullptr ? 2000000000 : node->leftChild->bestIndex;
	int right1 = node->rightChild == nullptr ? 2000000000 : node->rightChild->bestIndex;
	if (!(left1 == 2000000000 && right1 == 2000000000)) {
		int leftValue = left1 == 2000000000 ? 2000000000 : v.at(left1);
		int rightValue = right1 == 2000000000 ? 2000000000 : v.at(right1);
		if (leftValue == 2000000000 && rightValue == 2000000000) throw 7;
		node->bestIndex = leftValue <= rightValue ? left1 : right1;
		if (node->bestIndex == 2000000000) throw 8;
	}
	renewMinMax(node->parentNode, v);

	// node->parentNode->bestIndex = min(node->parentNode->bestIndex,node->bestIndex);

}



int main() {
	cin.tie(0);
	int N, M;
	cin >> N;
	vector<int> v(N + 1);
	for (size_t i = 0; i < N; i++)
	{
		cin >> v[i + 1];
	}
	nodeVector.push_back(nullptr);
	makeSegmentTree(N, v);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int query;
		cin >> query;
		if (query == 1) {
			int index, changeValue;
			cin >> index >> changeValue;
			v[index] = changeValue;
			renewMinMax(nodeVector[index], v);
		}
		else if (query == 2) {
			// 2번 쿼리
			int startIdx, endIdx;
			cin >> startIdx >> endIdx;
			int value = findBestValue(rootNode, startIdx, endIdx, v);
			cout << value << "\n";
		}
		else {
			throw invalid_argument("errrr");
		}
	}
}