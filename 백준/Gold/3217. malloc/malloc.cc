#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;



class Node {
public:
    int s, e;
    bool is_alloc;
    Node* prev_node = nullptr;
    Node* next_node = nullptr;
    Node(int s, int e, bool isAlloc) : s(s), e(e), is_alloc(isAlloc) {}
};


//list<Node*> lst;
unordered_map<string, Node*> mp;
Node* start_node;

void do_alloc(int want_size, string name) {
    if (want_size <= 0) {
        throw "err";
    }
    Node* cur = start_node;
    bool allocateSuccess = false;
    while (true) {
        int size = cur->e - cur->s + 1;
        // 이미 할당 또는 크기를 벗어나는 경우
        if (cur->is_alloc || want_size > size) {
            Node* next = cur->next_node;
            if (next == nullptr) break;
            else {
                cur = next;
            }
        }
        else {
            // 할당 가능한 경우

            // 크기가 동일하다면 할당 처리
            if (size == want_size) {
                cur->is_alloc = true;
                mp[name] = cur;
                allocateSuccess = true;
            }
            else {
                // 분할
                int before_s = cur->s;
                int before_e = cur->e;
                int next_s = before_s + want_size;
                cur->is_alloc = true;
                cur->e = before_s + want_size - 1;
                //                Node* new_split_node = new Node(cur->e+1,before_e,false);
                Node* next_node = cur->next_node; // 원래 노드의 다음 노드

                Node* new_split_node = new Node(next_s, before_e, false);
                cur->next_node = new_split_node;
                // 원래 노드의 다음노드가 존재하는 경우
                if (next_node != nullptr) {
                    if (!next_node->is_alloc) throw "err"; // 빈노드가 두개가 연속으로 있어서는 안됨
                    new_split_node->prev_node = cur;
                    new_split_node->next_node = next_node;
                    next_node->prev_node = new_split_node;
                }
                else {
                    // 원래 노드의 다음 노드가 없는 경우
                    new_split_node->prev_node = cur;
                }
                mp[name] = cur;
                allocateSuccess = true;
            }
            break;
        }
    }
    if (!allocateSuccess) {
        // 할당에 실패한경우 무시되는게 아니라 아예 없어져야함
        if (mp.contains(name)) {
            mp.erase(name);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcnt;
    cin >> tcnt;
    start_node = new Node(1, 100000, false);
    string answer = "";
    while (tcnt--) {
        string instruction;
        cin >> instruction;
        // malloc
        if (instruction.find("malloc(") != string::npos) {
            string var_name = instruction.substr(0, 4);
            int point1 = instruction.find("=");
            int point2 = instruction.find("(", point1 + 1);
            int point3 = instruction.find(")", point2 + 1);
            int alloc_size = stoi(instruction.substr(point2 + 1, point3 - (point2 + 1)));
            do_alloc(alloc_size, var_name);
        }
        else if (instruction.substr(0, 5) == "free(") { // free
            string var_name = instruction.substr(5, 4);
            // 만약 free할 변수가 없는 경우
            if (!mp.contains(var_name)) {
                continue;
            }
            // 할당 해제할 노드
            Node* cur_node = mp[var_name];
            bool is_first_node = cur_node->prev_node == nullptr;
            bool is_last_node = cur_node->next_node == nullptr;
            if (!cur_node->is_alloc) {
                throw "err";
            }
            else if (is_first_node && cur_node->s != 1) {
                throw "err";
            }
            else if (is_last_node && cur_node->e != 100000) {
                throw "err";
            }
            if (is_first_node && is_last_node) {
                cur_node->is_alloc = false;
                mp.erase(var_name);
                continue;
            }
            Node* next_node = cur_node->next_node;
            Node* prev_node = cur_node->prev_node;
            if (next_node != nullptr && next_node->s != cur_node->e + 1) throw "err";
            if (prev_node != nullptr && prev_node->e != cur_node->s - 1) throw "err";

            mp.erase(var_name);

            cur_node->is_alloc = false;
            if (next_node != nullptr) {
                // 다음 노드가 할당 안되어 있는 경우
                if (!next_node->is_alloc) {
                    // 다음 노드랑 합칠 수 있는 경우 >> 다음 노드 삭제
                    cur_node->e = next_node->e;
                    cur_node->next_node = next_node->next_node;
                    if (cur_node->next_node != nullptr) {
                        cur_node->next_node->prev_node = cur_node;
                    }
                }
            }

            if (prev_node != nullptr) {
                if (!prev_node->is_alloc) {
                    // 이전 노드랑 합칠 수 있는 경우 >> 현재 노드 삭제
                    prev_node->e = cur_node->e;
                    prev_node->next_node = cur_node->next_node;
                    if (cur_node->next_node != nullptr) {
                        cur_node->next_node->prev_node = prev_node;
                    }
                }
            }
        }
        else if (instruction.substr(0, 6) == "print(") { // print
            string var_name = instruction.substr(6, 4);
            if (!mp.contains(var_name)) {
                answer.append("0\n");
            }
            else {
                answer.append(to_string(mp[var_name]->s) + "\n");
            }
        }
        else {
            throw "err";
        }
    }
    cout << answer;
}