
N,M = map(int,input().split())
v = []

max_answer = 0
for _ in range(N):
    v.append(list(map(int,input().split())))



def solve_each(dy,dx):
    global max_answer
    for y in range(len(v)):
        for x in range(len(v[0])):
            can = True
            acc = 0
            for idx in range(4):
                ny = y+dy[idx]
                nx = x+dx[idx]
                if ny <0 or nx < 0 or ny>=len(v) or nx>=len(v[0]):
                    can = False
                    break
                acc += v[ny][nx]
            if not can:
                continue
            max_answer = max(max_answer,acc)

dy_sky = (0,0,0,0)
dx_sky = (0,1,2,3)
dy_yellow = (0,0,1,1)
dx_yellow = (0,1,0,1)
dy_orange = (0,1,2,2)
dx_orange = (0,0,0,1)
dy_green = (0,1,1,2)
dx_green = (0,0,1,1)
dy_pink = (0,0,0,1)
dx_pink = (0,1,2,1)
def solve():
    solve_each(dy_sky,dx_sky)
    solve_each(dy_yellow,dx_yellow)
    solve_each(dy_orange,dx_orange)
    solve_each(dy_green,dx_green)
    solve_each(dy_pink,dx_pink)


# (기본,좌우) (기본,180도) (0도,90도,180도,270도)


def flip_ud():
    global v
    new_v = []
    for row_idx in range(len(v)-1,-1,-1):
        new_v.append(v[row_idx].copy())
    v= new_v

def flip_lr():
    global v
    new_v = []
    for row_idx in range(len(v)):
        new_v.append(list(reversed(v[row_idx].copy())))
    v= new_v

def rotate_90():
    global v
    new_v = []
    for col_idx in range(len(v[0])):
        new_v.append([])
        for row_idx in range(len(v)-1,-1,-1):
            new_v[-1].append(v[row_idx][col_idx])
    v = new_v


# 기본 + 기본
for i in range(4):
    rotate_90()
    solve()

# 좌우 + 기본
flip_lr()
for i in range(4):
    rotate_90()
    solve()

# 좌우 + 상하
flip_ud()
for i in range(4):
    rotate_90()
    solve()

# 기본 + 상하
flip_lr() # 원상복구
for i in range(4):
    rotate_90()
    solve()

print(max_answer)

