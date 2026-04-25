n,m = map(int,input().split())
v = []

RIGHT = 10
LEFT = 12
UP = 11
DOWN = 13

dir1 = [RIGHT,UP,LEFT,DOWN] # 우,상,좌,하
dir2 = [20,21] # 좌우양방향 / 상하양방향
dir3 = [30,31,32,33]
dir4 = [40,41,42,43]
dir5 = [50]




def cal1(v,y,x,dir):
    r:range = None
    if dir == RIGHT or dir == LEFT:
        r = range(x,m) if dir == RIGHT else range(x,-1,-1)
        for nx in r:
            if v[y][nx] == 0:
                v[y][nx] = "#"
            elif v[y][nx] == 6:
                return
    elif dir == UP or dir == DOWN:
        r = range(y,n) if dir == DOWN else range(y,-1,-1)
        for ny in r:
            if v[ny][x] == 0:
                v[ny][x] = "#"
            elif v[ny][x] == 6:
                return


def cal2(v,y,x):
    if v[y][x] == "#" or v[y][x] < 10:
        return
    dir = v[y][x]

    if 10 <= dir < 20:
        cal1(v,y,x,dir)
    elif dir == 20:
        cal1(v,y,x,RIGHT)
        cal1(v,y,x,LEFT)
    elif dir == 21:
        cal1(v,y,x,11)
        cal1(v,y,x,13)
    elif dir == 30:
        cal1(v,y,x,UP)
        cal1(v,y,x,RIGHT)
    elif dir == 31:
        cal1(v,y,x,LEFT)
        cal1(v,y,x,UP)
    elif dir == 32:
        cal1(v,y,x,LEFT)
        cal1(v,y,x,DOWN)
    elif dir == 33:
        cal1(v,y,x,DOWN)
        cal1(v,y,x,RIGHT)
    elif dir == 40:
        cal1(v, y, x, RIGHT)
        cal1(v, y, x, UP)
        cal1(v, y, x, LEFT)
    elif dir == 41:
        cal1(v, y, x, UP)
        cal1(v, y, x, LEFT)
        cal1(v, y, x, DOWN)
    elif dir == 42:
        cal1(v, y, x, LEFT)
        cal1(v, y, x, DOWN)
        cal1(v, y, x, RIGHT)
    elif dir == 43:
        cal1(v, y, x, DOWN)
        cal1(v, y, x, RIGHT)
        cal1(v, y, x, UP)
    elif dir == 50:
        cal1(v, y, x, UP)
        cal1(v, y, x, LEFT)
        cal1(v, y, x, DOWN)
        cal1(v, y, x, RIGHT)
    else:
        exit(1)

def count_and_restore(v):
    cnt = 0
    for y in range(n):
        for x in range(m):
            if v[y][x] == "#":
                v[y][x] = 0
            elif v[y][x] == 0:
                cnt+=1

    return cnt



answer = 1000000000
def calc(v):
    global answer
    for y in range(n):
        for x in range(m):
            cal2(v,y,x)

    answer = min(count_and_restore(v),answer)


def dfs(v:list,y,x):
    global n,m
    if y == n:
        calc(v)
        return
    if not (v[y][x] == 6 or v[y][x] == 0):
        next_dir_arr = None
        if v[y][x] == 1:
            next_dir_arr=dir1
        elif v[y][x] == 2:
            next_dir_arr=dir2
        elif v[y][x] == 3:
            next_dir_arr=dir3
        elif v[y][x] == 4:
            next_dir_arr=dir4
        elif v[y][x] == 5:
            next_dir_arr=dir5

        for dir in next_dir_arr:
            before = v[y][x]
            v[y][x] = dir
            if x + 1 == m:
                dfs(v, y + 1, 0)
            else:
                dfs(v, y, x + 1)
            v[y][x] = before
    else: # 벽인 경우
        if x + 1 == m:
            dfs(v, y + 1, 0)
        else:
            dfs(v, y, x + 1)


for _ in range(n):
    v.append(list(map(int,input().split())))

dfs(v,0,0)
print(answer)
