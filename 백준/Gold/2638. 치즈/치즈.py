from collections import deque
import sys
sys.setrecursionlimit(10000000)

dy = (-1,1,0,0)
dx = (0,0,1,-1)
live_cheese:set[tuple[int,int]] = set()

N,M = map(int,input().split())
v = []
for _ in range(N):
    v.append(list(map(int,input().split())))
# 첫끝행_첫끝열은_2로
for k in range(M):
    v[0][k] = 2
    v[-1][k] = 2
for k in range(N):
    v[k][0] = 2
    v[k][-1] = 2


visit: set[tuple[int,int]] = set()
def propagate(y,x):
    visit.add((y,x))
    for idx in range(4):
        ny = y + dy[idx]
        nx = x + dx[idx]
        if ny <0 or nx<0 or ny>=N or nx>=M:
            continue
        if (ny,nx) in visit:
            continue
        if v[ny][nx] == 0:
            v[ny][nx] = 2
            propagate(ny,nx)

    visit.remove((y,x))

def is_melt_cheese(y,x):
    outer_air_cnt = 0
    for idx in range(4):
        ny = y + dy[idx]
        nx = x + dx[idx]
        if ny <0 or nx<0 or ny>=N or nx>=M:
            continue
        # 바깥공기를 마주친 경우
        if v[ny][nx] == 2:
            outer_air_cnt+=1
    return True if outer_air_cnt>=2 else False

for i in range(N):
    for j in range(M):
        if v[i][j] == 2:
            propagate(i,j)
        if v[i][j] == 1:
            live_cheese.add((i,j))

# 치즈들 중에 갈가먹힐 치즈들 계산
q: deque[tuple[int,int,int]] = deque() # y,x,time

def melt_cheese():
    while q:
        y,x,t = q.popleft()
        # code410932830921
        # 이미 바깥공기화가 된 경우
        if v[y][x] == 2 or (y,x) not in live_cheese:
            continue
        assert v[y][x] == 1 # 치즈여야함

        v[y][x] = 2 # 바깥공기로 변환
        live_cheese.remove((y,x))

        # 좌우 4개 방향을 보고, 혹시 안쪽공기가 바깥공기가 되는 경우 수정
        for idx in range(4):
            ny = y + dy[idx]
            nx = x + dx[idx]
            if ny <0 or nx<0 or ny>=N or nx>=M:
                continue
            if v[ny][nx] == 0: # 맑은 공기인 경우 : 일단전파
                v[ny][nx] = 2
                propagate(ny,nx)


def choose_melt_cheese():
    for tp in live_cheese:
        check_y,check_x = tp
        if v[check_y][check_x] == 1: # 치즈인경우
            if is_melt_cheese(check_y,check_x):
                q.append((check_y,check_x,1+1))

choose_melt_cheese()
if not q:
    print(0)
    exit(0)
for t_ in range(1,1000001):
    # 치즈를 녹이고
    melt_cheese()
    if not live_cheese:
        print(t_)
        exit(0)
    # 다음 녹을 치즈 선정
    choose_melt_cheese()
