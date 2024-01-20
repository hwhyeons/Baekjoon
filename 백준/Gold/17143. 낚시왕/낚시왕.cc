using namespace std;
#include <bits/stdc++.h>

int UP = 1;
int DOWN = 2;
int RIGHT = 3;
int LEFT = 4;
int R,C,M;



class Shark {

public:
    int row,column;
    int speed;
    int direction;
    // 1 : 위 / 2 : 아래 / 3 : 오른쪽 / 4: 왼쪽
    int big;
    Shark(){

    }
    Shark(int r, int c, int s, int d, int z) {
        this->row = r;
        this->column = c;
        this->speed = s;
        this->direction = d;
        this->big = z;
    };
    
    void moveUpDown() {
        int startRow = this->row;
        int af;
        if (this->direction == DOWN) {
            af = this->row + this->speed;
        } else {
            af = this->row - this->speed;
        }
        if (af >=0 && af < R) {
            this->row = af;
            return;
        }
        int lv;
        if (this->direction == DOWN ){
            lv = this->speed - (R-1-startRow); // 남은 이동 횟수 = 
        } else {
            lv = this->speed - startRow;
        }
        // lv = 4번
        int Q = (lv-1)/(R-1);
        if (Q%2==0) { // 몫이 짝수면 방향전환
            this->reverseDirection();
        }
        
        int ret = (lv)%(R-1); // 실질 이동거리 (1,2,3)
        if (ret == 0) {
            ret=R-1;
        }

        if (this->direction == DOWN) {
            this->row = ret;
        } else if (this->direction == UP) {
            this->row = (R-1)-ret;
        } else {
            throw "err";
        }
    }

    void moveLeftRight() {
        int startColumn = this->column;
        int af;
        if (this->direction == RIGHT) {
            af = this->column + this->speed;
        } else {
            af = this->column - this->speed;
        }
        if (af >=0 && af < C) {
            this->column = af;
            return;
        }
        int lv;
        if (this->direction == RIGHT){
            lv = this->speed - (C-1-startColumn); // 남은 이동 횟수 = 
        } else {
            lv = this->speed - startColumn;
        }
        // lv = 4번
        int Q = (lv-1)/(C-1);
        if (Q%2==0) { // 몫이 짝수면 방향전환
            this->reverseDirection();
        }
        
        int ret = (lv)%(C-1); // 실질 이동거리 (1,2,3)
        if (ret == 0) {
            ret=C-1;
        }

        if (this->direction == RIGHT) {
            this->column = ret;
        } else if (this->direction == LEFT) {
            this->column = (C-1)-ret;
        } else {
            throw "err";
        }
    }

    void moveShark() {
        if (this->direction == UP || this->direction == DOWN) {
            this->moveUpDown();
        } else {
            this->moveLeftRight();
        }
    }


    // void moveShark() {
    //     // 일단 먼저 이동 후에 나머지 연산으로 위치 계산
    //     int startRow = this->row;
    //     if (this->direction == UP) {
    //         this->row -= speed;
    //     } else if (this->direction == DOWN) {
    //         this->row += speed;
    //     } else if (this->direction == RIGHT) {
    //         this->column += speed;
    //     } else if (this->direction == LEFT) {
    //         this->column -= speed;
    //     } else {
    //         throw "error";
    //     }


    //     // 초과 했으면 보정
    //     if (this->row >= R){
    //         // 몫이 홀수면 방향 뒤집기
    //         if (((this->row)/(R-1))%2==1) {
    //             this->reverseDirection();
    //         }
    //         int idx = (this->row)%R;
    //         if (idx >= R) idx = R - (idx - R + 1);
    //         this->row = idx;
    //     } else if (this->row < 0) {
    //         if (((-1*this->row)/(R-1))%2==1) {
    //             this->reverseDirection();
    //         }
    //         int idx = (-1*this->row)%R;
    //         if (idx >= R) idx = R - (idx - R + 1);
    //         this->row = idx;
    //     } else if (this->column >= C) {
    //         if (((this->column)/(C-1))%2==1) {
    //             this->reverseDirection();
    //         }
    //         int idx = (this->column)%C;
    //         if (idx >= C) idx = C - (idx - C + 1);
    //         this->column = idx;
    //     } else if (this->column < 0) {
    //         if (((-1*this->column)/(C-1))%2==1) {
    //             this->reverseDirection();
    //         }   
    //         int idx = (-1*this->column)%C;
    //         if (idx >= C) idx = C - (idx - C + 1);
    //         this->column = idx;
    //     } else {
    //         // 아무 변화 X
    //     }
        
    // };

    void reverseDirection(){
        if (this->direction == UP) {
            this->direction = DOWN;
        } else if(this->direction == DOWN) {
            this->direction = UP;
        } else if (this->direction == LEFT) {
            this->direction = RIGHT;
        } else if (this->direction == RIGHT) {
            this->direction = LEFT;
        } else {
            throw "error reverse";
        }
    };
};

void eatingEach(vector<vector<vector<Shark>>>& v) {
    for (int i =0; i< R; i++) {
        for (int j=0; j < C; j++) {
            vector<Shark>& sharks = v.at(i).at(j);
            auto size1 = sharks.size();
            if (size1 <= 1) {
                continue;
            }
            // 서로 잡아먹기
            int maxIndex = 0;
            int maxSize = 0;
            for (size_t st=0; st<size1; st++) {
                if (sharks.at(st).big > maxSize) {
                    maxIndex = st;
                    maxSize = sharks.at(st).big;
                }
            }
            Shark newShark(sharks.at(maxIndex));
            vector<Shark> vs;
            vs.push_back(newShark);
            v.at(i).at(j) = vs;
        }
    }
}

void moveAllShark(vector<vector<vector<Shark>>>& v) {
    vector<vector<vector<Shark>>> newVec(R,vector<vector<Shark>>(C,vector<Shark>(0)));
    for (int i =0; i< R; i++) {
        for (int j=0; j < C; j++) {
            for (Shark skTmp : v.at(i).at(j)) {
                skTmp.moveShark();
                int newRow = skTmp.row;
                int newColumn = skTmp.column;
                newVec.at(newRow).at(newColumn).push_back(skTmp);
            }
        }
    }

    // cout << "-------이동 후--------\n";
    for (int i =0; i< R; i++) {
        for (int j=0; j < C; j++) {
            v.at(i).at(j) = newVec.at(i).at(j);
            // if (v.at(i).at(j).size() >=1 ){
                // cout << v.at(i).at(j).size() << " ";
            // } else {
                // cout << 0 << " ";
            // }
        }
        // cout << "\n";
    }
    
}

int fullEating = 0;
void playerFishing(vector<vector<vector<Shark>>>& v, int column) {
    for (int rowCur =0; rowCur < R; rowCur++) {
        int vSize = v.at(rowCur).at(column).size();
        if (vSize == 0) {
            continue;
        }
        if (vSize >= 2) {
            throw "preprocess error";
        }
        int eatTmp = v.at(rowCur).at(column).front().big;
        // cout << "낚시 : " << rowCur << " " << column << " " << eatTmp << "\n";
        fullEating += eatTmp;
        v.at(rowCur).at(column).clear();
        break;
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> R >> C >> M;
    vector<vector<vector<Shark>>> v(R,vector<vector<Shark>>(C,vector<Shark>(0)));
    for (size_t i = 0; i < M; i++)
    {
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        v.at(r-1).at(c-1).push_back(Shark(r-1,c-1,s,d,z));
    }
    
    for (size_t playerColumn = 0; playerColumn < C; playerColumn++) {
        playerFishing(v,playerColumn); // 플레이어가 먹는다
        moveAllShark(v);
        eatingEach(v); // 서로 잡아 먹는다
    }
    
    cout << fullEating;
    return 0;
}