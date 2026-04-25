R,C,T = map(int,input().split())
v = []
find_air_machine = False
air_machine_y  = 0

dys = [-1,1,0,0]
dxs = [0,0,1,-1]

for row in range(R):
    lst = list(map(int,input().split()))
    v.append(lst)
    if not find_air_machine and lst[0] == -1:
        air_machine_y = row
        find_air_machine = True

assert air_machine_y != 0

def expand_cell(r: int, c: int,new_v: list):
    # 공청기 칸 제외
    if v[r][c] == -1:
        return
    # 미세먼지가 없는 칸 제외
    if v[r][c] == 0:
        return

    expand_cnt = 0
    expand_amount = int(v[r][c]/5)
    for idx in range(4):
        dy = dys[idx]
        dx = dxs[idx]
        ny = r+dy
        nx = c+dx
        if ny<0 or nx<0 or ny>=R or nx>=C:
            continue
        if v[ny][nx] == -1: # 공청기가 있는 위치
            continue
        expand_cnt+=1
        new_v[ny][nx] += expand_amount
    new_v[r][c] -= expand_cnt*expand_amount




def expand_dust_full(new_v):
    # 모든 칸 확장 시작
    for r in range(R):
        for c in range(C):
            expand_cell(r,c,new_v)

def air_flow(new_v):
    # 윗방향 air_flow
    cur_y = air_machine_y
    cur_x = 0
    new_v_copy=[[0]*C for _ in range(R)]
    for r in range(R):
        for c in range(C):
            new_v_copy[r][c] = new_v[r][c]

    # 우측으로 C-1
    for _ in range(C-1):
        cur_x+=1
        if cur_x == 1:
            new_v[cur_y][cur_x] = 0
            continue
        new_v[cur_y][cur_x] = new_v_copy[cur_y][cur_x-1]

    assert cur_x == C-1
    # 위로 이동
    for _ in range(air_machine_y): # 위로 2번이동
        cur_y-=1
        new_v[cur_y][cur_x] = new_v_copy[cur_y+1][cur_x]

    assert cur_y == 0
    #왼쪽 이동
    for _ in range(C-1):
        cur_x-=1
        new_v[cur_y][cur_x] = new_v_copy[cur_y][cur_x+1]

    assert cur_x == 0
    #아래 이동
    for _ in range(air_machine_y-1): # 아래로 한번 이동
        cur_y+=1
        new_v[cur_y][cur_x] = new_v_copy[cur_y-1][cur_x]

    # ------------------------------
    # 아랫방향 air_flow
    cur_y = air_machine_y+1
    cur_x = 0

    # 오른쪽 이동
    for _ in range(C-1):
        cur_x+=1
        if cur_x == 1:
            new_v[cur_y][cur_x] = 0
            continue
        new_v[cur_y][cur_x] = new_v_copy[cur_y][cur_x-1]

    #아래 이동
    for _ in range(R-(air_machine_y+2)):
        cur_y+=1
        new_v[cur_y][cur_x] = new_v_copy[cur_y-1][cur_x]

    #왼쪽 이동
    for _ in range(C-1):
        cur_x-=1
        new_v[cur_y][cur_x] = new_v_copy[cur_y][cur_x+1]

    # 위로 이동
    for _ in range(R-(air_machine_y+3)):
        cur_y-=1
        new_v[cur_y][cur_x] = new_v_copy[cur_y+1][cur_x]



for _ in range(T):
    # new_v=[[0]*C for _ in range(R)]
    # new_v[air_machine_y][0] = -1
    # new_v[air_machine_y+1][0] = -1
    new_v=[[0]*C for _ in range(R)]
    for r in range(R):
        for c in range(C):
            new_v[r][c] = v[r][c]
    expand_dust_full(new_v)
    # for r in range(R):
    #     print(new_v[r])
    # print("\n\n")
    air_flow(new_v)
    # for r in range(R):
    #     print(new_v[r])
    v = new_v



# 누적 값 계산
acc = 0
for r in range(R):
    for c in range(C):
        if v[r][c] == -1: # 공청칸 무시
            continue
        acc+=v[r][c]
print(acc)