class g:
    ans = 0 # 청소한 개수

N,M = map(int,input().split())
cur_y,cur_x,g.cur_dir = map(int,input().split()) # 로봇의 현재 위치


# 방향 : 북쪽 0 / 동쪽 1 / 남쪽 2 / 서쪽 3
NORTH = 0
EAST = 1
SOUTH = 2
WEST = 3

NOT_CLEAN = 0
WALL = 1
CLEANED = 2

v = [] # 2차원 배열
for _ in range(N):
    v.append(list(map(int,input().split())))


# 바라보고 있는 방향의 좌표
def get_dir_yx():
    if g.cur_dir == NORTH:
        return cur_y-1,cur_x
    elif g.cur_dir == EAST:
        return cur_y,cur_x+1
    elif g.cur_dir == SOUTH:
        return cur_y+1,cur_x
    elif g.cur_dir == WEST:
        return cur_y,cur_x-1
    else:
        raise "err"


def clean_current():
    # 현재위치_청소
    global v
    if v[cur_y][cur_x] != NOT_CLEAN:
        raise "err"
    v[cur_y][cur_x] = CLEANED
    g.ans+=1

def move(y,x):
    global cur_y,cur_x
    cur_y,cur_x = y,x

def rotate():
    # 반시계90도회전;
    if g.cur_dir == NORTH:
        g.cur_dir = WEST
    elif g.cur_dir == EAST:
        g.cur_dir = NORTH
    elif g.cur_dir == SOUTH:
        g.cur_dir = EAST
    elif g.cur_dir ==  WEST:
        g.cur_dir = SOUTH
    else:
        raise "err"
    
# loop1
while True:
    if v[cur_y][cur_x] == NOT_CLEAN:
        clean_current()
    else: # 현재위치는_청소됨
        # new_clear= False
        before_dir = g.cur_dir # 방향 저장
        tf_type2 = False
        for _ in range(4): # 4방향 확인
            rotate()
            y_dir,x_dir = get_dir_yx()
            if (0 <= y_dir < N and 0 <= x_dir < M) and v[y_dir][x_dir] == NOT_CLEAN:
                tf_type2 = True
                break
        g.cur_dir = before_dir # 방향 되돌리기
        if tf_type2: # 청소안된 빈칸이 있는 경우
            rotate() # 반시계 방향으로 90도 회전한다
            y_dir2, x_dir2 = get_dir_yx() #바라보는 방향을 기준으로 앞쪽 칸이
            if (0 <= y_dir2 < N and 0 <= x_dir2 < M) and v[y_dir2][x_dir2] == NOT_CLEAN: # 청소되지 않은 빈칸인 경우
                move(y_dir2,x_dir2) # 한칸 전진한다
            continue # 1번으로 되돌아간다
        else:
            # 그 후, 뒤를 바라보기 위해 다시 두번 회전
            rotate();rotate()
            y_dir,x_dir = get_dir_yx()
            # 후진할 수 있는 경우 (벽만 아니면 됨)
            if (0 <= y_dir < N and 0 <= x_dir < M) and v[y_dir][x_dir]!=WALL:
                # 다시 원래 방향으로 되돌린다
                g.cur_dir = before_dir
                move(y_dir,x_dir)
                continue # loop1 진행
            else:
                break # loop1종료
        

print(g.ans)
