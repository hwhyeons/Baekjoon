
#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;



int lastIdx;

class Node {
public:
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    int s,e;
    ll acc = 0LL;
    ll min_val = LLONG_MAX; // 백준 14438 풀이용


    // 한번만 호출 해도 됨
    void make_child_empty(vector<Node*>& leaf_all) {
        if (s == e) {
            leaf_all[s] = this;
            return;
        }
        int left_s = s;
        int left_e = (s+e)/2;
        int right_s = left_e+1;
        int right_e = e;
        Node* left = new Node;
        Node* right = new Node;
        this->left = left;
        this->right = right;

        left->s = left_s;
        left->e = left_e;
        left->parent = this;
        right->s = right_s;
        right->e = right_e;
        right->parent = this;
        left->make_child_empty(leaf_all);
        right->make_child_empty(leaf_all);
    }

    ll get_sum(int start, int end) {
        if (start == s && end == e) {
            return acc;
        }
        int left_e = this->left->e;
        int right_s = this->right->s;
        if (end <= left_e){ // 왼쪽에 다 포함
            return this->left->get_sum(start,end);
        } else if (start <= left_e && end >= right_s) { // 양쪽에 걸친 경우
            return this->left->get_sum(start,left_e) + this->right->get_sum(right_s,end);
        } else { // 오른쪽에 몰린 경우
            return this->right->get_sum(start,end);
        }
    }

    ll get_min_val(int start, int end) {
        if (start == s && end == e) {
            return min_val;
        }
        int left_e = this->left->e;
        int right_s = this->right->s;
        if (end <= left_e){ // 왼쪽에 다 포함
            return this->left->get_min_val(start,end);
        } else if (start <= left_e && end >= right_s) { // 양쪽에 걸친 경우
            return min(this->left->get_min_val(start,left_e),this->right->get_min_val(right_s,end));
        } else { // 오른쪽에 몰린 경우
            return this->right->get_min_val(start,end);
        }
    }

    void update_val() {
        if (s == e) {
            throw 1; // 이 함수는 리프에서 호출 X
        }
        this->acc = this->left != nullptr ? this->left->acc : 0LL;
        this->acc += this->right != nullptr ? this->right->acc : 0LL;
        ll l_val = this->left != nullptr ? this->left->min_val : LLONG_MAX;
        ll r_val = this->right != nullptr ? this->right->min_val : LLONG_MAX;
        this->min_val = min(l_val,r_val);
        if (this->parent != nullptr) {
            (this->parent)->update_val();
        }
    }

    void init_update() { // 루트부터 아래로 갱신 : 주의 >> 맨 처음에만 사용해야함 (이후에 사용시 시간 초과)
        if (s == e) {
            this->min_val = acc;
            return;
        }
        ll left_sum = 0LL;
        ll right_sum = 0LL;
        if (left != nullptr) {
            left->init_update();
            left_sum = left->acc;
            this->min_val = min(this->min_val,left->min_val);
        }
        if (right != nullptr) {
            right->init_update();
            right_sum = right->acc;
            this->min_val = min(this->min_val,right->min_val);
        }
        this->acc = left_sum+right_sum;
    }
};

class Tree {
public:
    Node* root;
    Tree(){
        root = new Node;
        root->s = 1;
        root->e = lastIdx;
    }

    void renew(vector<Node*>& leaf_all,int idx,ll new_val) {
        Node* leaf = leaf_all[idx];
        leaf->acc = new_val;
        leaf->min_val = new_val; // 리프노드이므로 자기 자신이 최소값
        if (leaf->parent != nullptr) {
            leaf->parent->update_val();
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> v(n);
    lastIdx = n;
    Tree tree;
    vector<Node*> leaf_all(n+1);
    (tree.root)->make_child_empty(leaf_all);
    for (int i = 1; i <= n; ++i) {
        int tmp; cin >> tmp;
        leaf_all[i]->acc = tmp;
        leaf_all[i]->min_val = tmp;
    }


    (tree.root)->init_update(); // 아래 방향 첫 갱신
    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int type,t1,t2;
        cin >> type>>t1>>t2;
        if (type == 2) {
            if (t1 == t2) {
                cout << leaf_all[t1]->acc << "\n";
            } else cout << (tree.root)->get_min_val(t1,t2) << "\n";
        } else { // type 1
            tree.renew(leaf_all,t1,t2);
        }
    }
}