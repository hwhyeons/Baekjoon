#include <bits/stdc++.h>
#include <ranges>

typedef long long ll;

using namespace std;

class Line {
public:
    int id; // 고유 아이디
    int x1,y1,x2,y2;
    Line* parent;
    double len; // (루트 처리 전 길이)
    Line(int id, int x1, int y1, int x2, int y2) : id(id), x1(x1), y1(y1), x2(x2), y2(y2){
        this->len = pow(x2-x1,2) + pow(y2-y1,2);
        this->parent = this;
    }
};

// -1,0,1
int ccw(int x1, int y1, int x2, int y2,int x3, int y3) {
    ll k = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if  (k > 0) {
        return 1;
    } else if (k == 0) {
        return 0;
    } else {
        return -1;
    }
}
vector<Line*> lines;

Line* getParent(Line* line) {
    if (line->parent->id == line->id) return line;
    else {
        line->parent = getParent(line->parent);
    }
    return line->parent;
}

void merge(Line* l1, Line* l2) {
    Line* p1 = getParent(l1);
    Line* p2 = getParent(l2);
    if (p1->parent == p2->parent) {
        return;
    } else {
        if (p1->id < p2->id) {
            p1->parent = p2;
        } else {
            p2->parent = p1;
        };
    }
}

bool isLineCross(Line* l1, Line* l2) {
    auto p1 = make_pair(l1->x1,l1->y1);
    auto p2 = make_pair(l1->x2,l1->y2);
    auto p3 = make_pair(l2->x1,l2->y1);
    auto p4 = make_pair(l2->x2,l2->y2);
    int a = ccw(p1.first,p1.second,p2.first,p2.second,p3.first,p3.second);
    int b = ccw(p1.first,p1.second,p2.first,p2.second,p4.first,p4.second);
    int c = ccw(p3.first,p3.second,p4.first,p4.second,p1.first,p1.second);
    int d = ccw(p3.first,p3.second,p4.first,p4.second,p2.first,p2.second);
    if (a*b == 1 || c*d == 1) return false;
    else if ((a == 0 && b == 0) || (c == 0 && d == 0)) {
        // 안겹치는 경우
        if (max(p3.first,p4.first) < min(p1.first,p2.first) || min(p3.first,p4.first) > max(p1.first,p2.first)) {
            return false;
        } else if (max(p3.second,p4.second) < min(p1.second,p2.second) || min(p3.second,p4.second) > max(p1.second,p2.second)) {
            return false;
        } else {
            return true;
        }
    } else if (a * b == 0 || c * d == 0) { // 하나라도 0이면 반대 부호 테스트
        if (a * b == 0) {
            if (c*d == 1) return false;
        } else {
            if (a*b == 1) return false;
        }
        return true;
    } else {
        return true;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int lineCnt;
    cin >> lineCnt;
    int maxLineId = 0;
    double maxLen = -1;
    for (int i = 0; i < lineCnt; ++i) {
        int t1,t2,t3,t4;
        cin >> t1 >> t2 >> t3 >> t4;
        // 처음에는 자기 자신이 그룹
        Line *ltmp = new Line(i, t1, t2, t3, t4);
        lines.push_back(ltmp);
        if (ltmp->len > maxLen) {
            maxLen = ltmp->len;
            maxLineId = i;
        }
    }

    // 전부 그룹화
    for (int i = 0; i < lineCnt; ++i) {
        for (int j = i+1; j < lineCnt; ++j) {
            Line* l1 = lines.at(i);
            Line* l2 = lines.at(j);
            if (isLineCross(l1,l2)) {
                merge(l1,l2);
            }
        }
    }

    int maxGroupID = -1;

    // 그룹개수 및 최대값 계산
    unordered_map<int,int> groups;
    for (int i = 0; i < lineCnt; ++i) {
        Line* parent = getParent(lines.at(i));
        int id = parent->id;
        if (groups.contains(id)) {
            groups[id]+=1;
        } else {
            groups[id] = 1;
        }
//        // 아까 최대 계산해놓은 선분이 현재 선분이면, 해당 선분이 속한 그룹을 최대 그룹으로
//        if (i == maxLineId) { >> 문제 잘못이해함
//            maxGroupID = id;
//        }
    }
    cout << groups.size() << "\n";
    int mx= -1;
    for (auto k: groups) {
        mx = max(mx,k.second);
    }
    cout << mx;

}