
v = [[0 for _ in range(101)] for _ in range(101)]

cur_dir = 0
rv = False
order_list = []

def calDir(y,x,cur_dir):
    if cur_dir == 0:
        return y,x+1
    elif cur_dir == 1:
        return y-1,x
    elif cur_dir == 2:
        return y,x-1
    elif cur_dir == 3:
        return y+1,x

def bef_dir(d):
    if d == 0:
        return 3
    else:
        return d-1


def nextDir(d):
    if d == 3:
        return 0
    else:
        return d+1

# 무조건 반시계방향
def rotate_dir(d):
    if d == 0:
        return 3
    else:
        return d-1


def rev_dir(d):
    if d == 0:
        return 2
    elif d == 1:
        return 3
    elif d == 2:
        return 0
    elif d == 3:
        return 1

def is_dec(i1,i2):
    if i1 == 3 and i2 == 0:
        return False
    elif i1 == 0 and i2 == 3:
        return True
    elif i1 - i2 == 1:
        return True
    elif i1 - i2 == -1:
        return False



def draw(y, x, max_gen):
    global v,cur_dir,rv
    # print("draw : ",max_gen)
    # print(max_gen)
    if max_gen == 0 or max_gen == 1:
        # print("방향 : ",cur_dir)
        v[y][x] = 1
        ny, nx = calDir(y, x, cur_dir)
        v[ny][nx] = 1
        order_list.append(cur_dir)
        return ny, nx
    else:
        ny,nx = calDir(y,x,cur_dir)
        v[ny][nx] = 1
        order_list.append(cur_dir)
        for idx in range(len(order_list)-2,0,-1):
            if is_dec(order_list[idx],order_list[idx-1]):
                cur_dir = bef_dir(cur_dir)
                ny, nx = calDir(ny,nx,cur_dir)
            else:
                cur_dir = nextDir(cur_dir)
                ny, nx = calDir(ny,nx,cur_dir)
            v[ny][nx] = 1
            order_list.append(cur_dir)
        return ny,nx


def print_count():
    cnt = 0;
    for i in range(100):
        for j in range(100):
            if v[i][j] == 1 and v[i+1][j] == 1 and v[i][j+1] and v[i+1][j+1] == 1:
                cnt+=1
    print(cnt)

if __name__ == '__main__':

    n = int(input())

    for i in range(n):
        x,y,d,gen = map(int,input().split())
        cur_dir = d
        ny,nx = y,x
        for j in range(gen+1):
            ny,nx= draw(ny,nx,j)
            cur_dir = rev_dir(cur_dir)
            cur_dir = rotate_dir(cur_dir)
        order_list.clear()

    print_count();
