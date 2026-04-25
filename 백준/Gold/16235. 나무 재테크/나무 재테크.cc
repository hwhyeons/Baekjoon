#include <iostream>
#include <iomanip>
#include <ranges>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>
#include <ranges>
// #include<bits/stdc++.h>
#include <limits>
typedef long long ll;
typedef long double ld;
using namespace std;

int global_ID = 0;
int N,M,K;

class Tree {
public:
    int age;
    int id; // 그냥 고유값 (treeset 중복문제 해결)

    // 여기서id도정렬에 포함해야됨 : TreeSet 정렬 중복값 처리 원리
    bool operator<(const Tree& other) const {
        if (this->age != other.age) {
            return this->age < other.age;
        }
        return this->id < other.id;
    }

    Tree(int age) {
        this->id = global_ID;
        ++global_ID;
        this->age = age;
    }
};

class Node {
public:
    vector<Tree> trees;
    int food = 5; // 양분. 기본값 5
    int S2D2_ADD; // const

    void workS2D2() {
        this->food += S2D2_ADD;
    }
};

void springAndSummer(vector<vector<Node>>& v) {
    // 나이만큼 양분 먹이기
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            auto& curNode = v[i][j];
            // vector<Tree>& trees = curNode.trees;
            int killStartIndex = -1;
            // int beforeTreeAge = 0; // 정렬 체크
            for (int k =0; k<curNode.trees.size(); k++) {
                auto& tree = curNode.trees[k];
                // if (tree.age < beforeTreeAge) throw "sort";
                // beforeTreeAge = tree.age;
                // 양분을 먹이는 경우
                if (tree.age <= curNode.food) {
                    curNode.food -= tree.age;
                    tree.age += 1;
                    continue;
                }

                // 양분을 못먹이는 경우
                // 그 뒤 나무를 전부 죽여야함
                killStartIndex = k;
                break;
            }

            // 죽일 나무가 있는 경우
            if (killStartIndex != -1) {
                // 양분을 미리 추가하기
                for (int k = killStartIndex; k<curNode.trees.size(); k++) {
                    curNode.food += (curNode.trees[k].age)/2;
                }
                // 나무 제거
                curNode.trees.erase(curNode.trees.begin()+killStartIndex,curNode.trees.end());
            }

        }
    }

}


// 인접한 칸 트리 추가
void add_adj_tree(vector<vector<Node>>& v, Tree& tree, int y, int x) {

    int dy[] = {-1,-1,-1,1,1,1,0,0};
    int dx[] = {-1,1,0,-1,1,0,-1,1};
    for (int idx=0; idx<8; idx++) {
        int ny = y+dy[idx];
        int nx = x+dx[idx];
        if (ny <0 || nx <0 || ny>=N || nx>= N) continue;
        v[ny][nx].trees.push_back({1});
    }

}

void autumn(vector<vector<Node>>& v) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (Tree& tree : v[i][j].trees) {
                // 나무의 나이가 5의 배수
                if (tree.age%5 == 0) {
                    add_adj_tree(v,tree,i,j);
                }
            }
        }
    }

}

void winter(vector<vector<Node>>& v) {
    // 양분주기 작업
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            v[i][j].workS2D2();
        }
    }
}

void sort_all_tree(vector<vector<Node>>& v) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!v[i][j].trees.empty()) {
                sort(v[i][j].trees.begin(),v[i][j].trees.end());
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    vector<vector<Node>> v; //
    v.assign(N,vector<Node>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int tmp;
            cin >> tmp;
            v[i][j].S2D2_ADD = tmp;
        }
    }
    for (int i = 0; i < M; ++i) {
        int x,y,z;
        cin >> x >> y>> z;
        v[x-1][y-1].trees.push_back({z});
    }

    for (int curYear=0; curYear <= K-1; curYear++) {
        springAndSummer(v);
        autumn(v);
        winter(v);
        sort_all_tree(v);
    }


    // 순회해서 나무 개수
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            answer += v[i][j].trees.size();
        }
    }
    cout << answer;


}