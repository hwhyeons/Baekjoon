import itertools

n = int(input())
v = []
teacher_point: list[tuple[int,int]] = []
for i in range(n):
    spt = input().split()
    for j in range(n):
        if spt[j] == 'T':
            teacher_point.append((i,j))
    v.append(spt)

def convert2yx(index: int) -> tuple[int,int]:
    y = index//n
    x = index%n
    return y,x


def is_already_on(y,x) -> bool:
    # 이미 다른게 놓여있는지
    if v[y][x] != 'X':
        return True
    return False

def calculate() -> bool:
    # 한명이라도 발견하면 return False
    global v
    for tp in teacher_point:
        teacher_y,teacher_x = tp
        # y축과 x축방향으로 확인. 오브젝트 발견 또는 인덱스 초과시 끝
        # 왼쪽 방향
        for xn in range(teacher_x-1,-1,-1):
            val = v[teacher_y][xn]
            if val == 'S':
                return False
            if val == 'O': # 벽 발견시
                break

       # 오른쪽 방향
        for xn in range(teacher_x+1,n):
            val = v[teacher_y][xn]
            if val == 'S':
                return False
            if val == 'O': # 벽 발견시
                break

        # 위쪽 방향
        for yn in range(teacher_y-1,-1,-1):
            val = v[yn][teacher_x]
            if val == 'S':
                return False
            if val == 'O': # 벽 발견시
                break

        # 아래쪽 방향
        for yn in range(teacher_y+1,n):
            val = v[yn][teacher_x]
            if val == 'S':
                return False
            if val == 'O': # 벽 발견시
                break
    return True


comb = itertools.combinations(range(n*n),3)

while (t:=next(comb,None)):
    y1,x1 = convert2yx(t[0])
    y2,x2 = convert2yx(t[1])
    y3,x3 = convert2yx(t[2])
    if is_already_on(y1,x1) or is_already_on(y2,x2) or is_already_on(y3,x3):
        continue
    v[y1][x1] = 'O'
    v[y2][x2] = 'O'
    v[y3][x3] = 'O'
    if calculate():
        print("YES")
        exit(0)
    v[y1][x1] = 'X'
    v[y2][x2] = 'X'
    v[y3][x3] = 'X'
print("NO")

