#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <limits.h>
#include <queue>

using namespace std;




class Tomato {
public:
    int val; // -1 0 1
    int time = 0;
    int y,x;
    
    Tomato(int val, int time, int y, int x) : val(val) , time(time) , y(y), x(x){}
    
    // bool operator<(const Tomato& t) const {
    //     cout << "operator\n";
    //     return this->time > t.time;
    // }

    // bool operator<(const Tomato* t) const {
    //     cout << "operator123\n";
    //     return this->time > t->time;
    // }

    // bool operator()(const Tomato* t1, const Tomato* t2) const {
    //     cout << "struct\n";
    //     return t1->time > t2->time;
    // }
};

struct CmpStruct
{
    bool operator()(const Tomato* lhs, const Tomato* rhs) const
    {
        return lhs->time > rhs->time;
    }
};

vector<vector<Tomato*>> v;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs() {
    int left_cnt = 0;
    int width = v[0].size();
    int height = v.size();

    priority_queue<Tomato*,vector<Tomato*>,CmpStruct> pq;
    // 처음에는 미리 넣어두기
    for (int i =0; i< height; i++) {
        for (int j =0; j< width; j++) {
            if (v[i][j]->val == 1) { // 익은 토마토 
                pq.push(v[i][j]);
            } else if (v[i][j]->val == 0) { // 안익은 토마토 개수
                left_cnt++;
            }
        }
    }
    int cur_time = 0;
    while (!pq.empty()) {
        Tomato* cur = pq.top(); pq.pop();
        cur_time = max(cur_time,cur->time);
        int x_cur = cur->x;
        int y_cur = cur->y;
        for (int i =0; i<4; i++) {
            int nx = x_cur + dx[i];
            int ny = y_cur + dy[i];
            if (nx < 0 || ny <0 || nx >= width || ny >= height) continue;
            if (v[ny][nx]->val == 0) { // 안익은 토마토 발견
                // if (v[ny][nx]->time == cur->time+1) { // 이미 우선순위 큐에 넣은 경우 (방문 완료)
                //     continue;
                // }
                v[ny][nx]->time = cur->time+1;
                v[ny][nx]->val = 1;
                pq.push(v[ny][nx]);
                left_cnt--;
            }
        }
    }

    if (left_cnt != 0) { // 토마토가 남았는데 반복문이 종료된 경우 : 토마토가 다 익지 못함
        return -1;
    }

    return cur_time;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w,h;
    cin >> w >> h;
    v = vector<vector<Tomato*>>(h,vector<Tomato*>(w));
    for (int i =0; i<h; i++) {
        for (int j =0; j<w; j++) {
            int t; cin >> t;
            Tomato* tmp = new Tomato(t,0,i,j);
            v[i][j] = tmp;
        }
    }
    cout << bfs();


}