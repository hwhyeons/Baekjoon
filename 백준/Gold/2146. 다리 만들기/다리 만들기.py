from collections import deque
import sys
sys.setrecursionlimit(10**6)
# 메모리 초과 -> pypy 대신 python / recursionlimit 제한 하기
input = sys.stdin.readline

dydx = ((1,0),(-1,0),(0,1),(0,-1))

next_group = 1

min_answer = 100000000

def dfs(y,x,gn):
    global v,group_num,N
    group_num[(y,x)] = gn
    for dy,dx in dydx:
        ny = y + dy
        nx = x + dx
        if 0<=ny<N and 0<=nx<N:
            if v[ny][nx] == 0: # land
                continue
            if (ny,nx) in group_num:
                continue
            dfs(ny,nx,gn)


def make_group():
    global v,next_group,N,group_num
    for i in range(N):
        for j in range(N):
            if v[i][j] == 0: # 바다인 경우
                continue
            if (i,j) in group_num:
                continue
            dfs(i,j,next_group)
            next_group+=1



bfs_cnt = 1
vst = dict()
def bfs(y,x):
    global N,min_answer,bfs_cnt
    bfs_cnt += 1
    cur_group = group_num[(y, x)]
    d = deque()
    d.appendleft((y,x,0))
    vst[(y,x)] = bfs_cnt
    flag = False
    while len(d) > 0:
        cur_y,cur_x,dist = d.popleft()
        if flag: break
        for dy, dx in dydx:
            ny = cur_y + dy
            nx = cur_x + dx
            if not (0 <= ny < N and 0 <= nx <= N):
                continue
            if (ny,nx) in group_num:
                if group_num[(ny,nx)] != cur_group: # 육지긴 한데 같은 육지
                    min_answer = min(min_answer,dist)
                    flag = True
                    break
            else: # 바다인 경우
                if (ny,nx) in vst and vst[(ny,nx)] == bfs_cnt: # 이미 방문한 바다
                    continue
                vst[(ny,nx)] = bfs_cnt
                d.append((ny,nx,dist+1))





def find_best():
    global N,group_num
    for i in range(N):
        for j in range(N):
            if (i,j) in group_num:
                bfs(i,j)




N = int(input().strip())
v = [list(map(int,input().split())) for _ in range(N)]
group_num = dict()

make_group()

find_best()

print(min_answer)