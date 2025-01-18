from collections import deque
N,M,T = map(int,input().split())

v: list[deque[int]] = []


# 한 줄만 돌리기
def rotate(line_idx: int, is_clock: bool,rotate_cnt: int):
    global v
    # rotate호출은_인덱스호출임(1빼기)
    # is_clock : 시계방향인지
    assert line_idx < N
    for cnt in range(rotate_cnt):
        v[line_idx].rotate(1 if is_clock else -1)


# 하나라도 지우면 true
def remove_all_adj() -> bool:
    global v

    remove_rowcol = []
    # 가로방향 처리
    for row in range(N):
        for col in range(M):
            adj_col = col -1
            if col == 0:
                adj_col = M-1
            right = v[row][col]
            left = v[row][adj_col]
            if right != 'x' and left != 'x' and right == left:
                remove_rowcol.append((row,col))
                remove_rowcol.append((row,adj_col))

    # 세로방향 처리 -> 이거는 인접이 다름
    for col in range(M):
        for row in range(N):
            adj_row = row -1
            if row == 0: # 주의 : row는 순환 X
                continue
            up = v[row][col]
            down = v[adj_row][col]
            if up != 'x' and down != 'x' and up == down:
                remove_rowcol.append((row,col))
                remove_rowcol.append((adj_row,col))


    # x는리턴불에 영향안줌
    return_bool = True if remove_rowcol else False
    for r,c in remove_rowcol:
        v[r][c] = 'x'
    return return_bool

def get_average() -> float:
    cnt = 0 # x의 개수
    acc = 0
    for r in range(N):
        for c in range(M):
            if v[r][c] == 'x':
                continue
            cnt+=1
            acc+=v[r][c]
    if cnt == 0:
        return 0
    return acc/cnt

# +1, -1 등의 작업
def modify_number() -> None:
    global v
    avg:float = get_average()
    for r in range(N):
        for c in range(M):
            val = v[r][c]
            if val == 'x':
                continue
            if val > avg:
                v[r][c] -=1
            elif val < avg:
                v[r][c] += 1





for _ in range(N):
    v.append(deque(map(int, input().split())))
for _ in range(T):
    x,d,k = map(int,input().split())
    is_clock = True if d == 0 else False
    # 배수 돌리기
    for l in range(x,N+1,x):
        rotate(l-1,is_clock,k)

    # 지우기 실패한 경우
    if not remove_all_adj():
        modify_number()

acc = 0
for r in range(N):
    for c in range(M):
        if v[r][c] == 'x':
            continue
        acc+=v[r][c]
print(acc)