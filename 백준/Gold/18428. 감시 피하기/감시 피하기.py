
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




for i in range(n*n):
    y1,x1 = convert2yx(i)
    if is_already_on(y1, x1):
        continue
    before_1 = v[y1][x1]
    v[y1][x1] = 'O'
    for j in range(i+1,n*n):
        y2, x2 = convert2yx(j)
        if is_already_on(y2,x2):
            continue
        before_2 = v[y2][x2]
        v[y2][x2] = 'O'
        for k in range(j+1,n*n):
            y3, x3 = convert2yx(k)
            if is_already_on(y3, x3):
                continue
            before_3 = v[y3][x3]
            v[y3][x3] = 'O'
            success = calculate()
            if success:
                print("YES")
                exit(0)
            v[y3][x3] = before_3
        v[y2][x2] = before_2
    v[y1][x1] = before_1
print("NO")
