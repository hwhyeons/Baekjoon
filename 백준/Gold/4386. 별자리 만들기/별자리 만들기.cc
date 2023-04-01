
#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

// idx1과 idx2사이의 거리
double get_dist(vector<pair<double,double>>& v, int idx1, int idx2) {
    double tmp1 = v[idx1].first - v[idx2].first;
    double tmp2 = v[idx1].second - v[idx2].second;
    return sqrt(pow(tmp1,2)+pow(tmp2,2));
}

int get_parent_idx(vector<int>& parents, int idx) {
    if (parents[idx] == idx) {
        return idx;
    } else {
        return get_parent_idx(parents,parents[idx]);
    }
}

class Edge {
public:
    int idx1;
    int idx2;
    double dist;
    Edge(int idx1, int idx2, double dist) : idx1(idx1),idx2(idx2),dist(dist) {};
};


// return : success -> dist / fail -> -100.0
bool do_union(vector<int>& parents, Edge& edge){
    int idx1 = edge.idx1;
    int idx2 = edge.idx2;
    int parent1 = get_parent_idx(parents,idx1);
    int parent2 = get_parent_idx(parents,idx2);
    if (parent1 == parent2) {
        return false;
    }
    if (parent1 < parent2) {
        parents[parent2] = parent1;
    } else {
        parents[parent1] = parent2;
    }
    return true;
}


bool compare(const Edge& e1,const Edge& e2) {
    return e1.dist < e2.dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<double,double>> v(n); // x, y
    for (int i = 0; i < n; ++i) {
        double t1,t2;
        cin >> t1 >> t2;
        v[i] = make_pair(t1,t2);
    }
//    vector<vector<double>> dists(n,vector<double>(n));
    deque<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double d = get_dist(v,i,j);
            edges.emplace_back(i,j,d);
        }
    }

    // sort
    sort(edges.begin(),edges.end(),compare);

    vector<int> parents(n);
    iota(parents.begin(), parents.end(),0); // 자기 자신이 부모
    double answer = 0.0;
    while (!edges.empty()) {
        Edge cur_edge = edges.front(); edges.pop_front();
        bool tmp = do_union(parents,cur_edge); // 실패하면 알아서 다음 것으로
        if (tmp) {
            answer += cur_edge.dist;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << answer;

}