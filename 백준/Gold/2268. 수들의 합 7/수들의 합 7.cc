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
    ll value = 0LL;

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
            return value;
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

    void update_val() {
        if (s == e) {
            throw 1; // 이 함수는 리프에서 호출 X
        }
        this->value = this->left != nullptr ? this->left->value : 0LL;
        this->value += this->right != nullptr ? this->right->value : 0LL;
        if (this->parent != nullptr) {
            (this->parent)->update_val();
        }
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
        leaf->value = new_val;
        if (leaf->parent != nullptr) {
            leaf->parent->update_val();
        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<ll> v(n);
    lastIdx = n;
    Tree tree;
    vector<Node*> leaf_all(n+1);
    (tree.root)->make_child_empty(leaf_all);
    for (int i = 0; i < m; ++i) {
        int type,t1,t2;
        cin >> type>>t1>>t2;
        // type 0 : get sum
        if (type == 0) {
            if (t1 > t2) swap(t1,t2);
            if (t1 == t2) {
                cout << leaf_all[t1]->value << "\n";
            } else cout << (tree.root)->get_sum(t1,t2) << "\n";
        } else {
            tree.renew(leaf_all,t1,t2);
        }
    }
}

