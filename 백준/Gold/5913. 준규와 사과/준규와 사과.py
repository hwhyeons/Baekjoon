K = int(input())
v = []
for _ in range(5):
    v.append(['.','.','.','.','.'])

v[0][0] = 'o'
v[4][4] = 'o'
APP_COUNT = 25-K
for _ in range(K):
    i,j = map(int,input().split())
    v[i-1][j-1] = 'x'

dxdy = ((1,0),(-1,0),(0,1),(0,-1))

h_pos = (4,4) # 현재 해빈 위치
j_pos = (0,0) # 현재 준규 위치

left_app_count = APP_COUNT-2
answer = 0


def dfs(is_second_turn: bool,cur_y,cur_x):
    global h_pos,j_pos,left_app_count,answer
    # 준규  -> 해빈 순으로 시작
    # print(*v,sep='\n',end='\n\n')

    for dy,dx in dxdy:
        ny = cur_y + dy
        nx = cur_x + dx
        if not (0 <= ny < 5):
            continue
        elif not (0 <= nx < 5):
            continue
        elif (ny == 0 and nx == 0) or (ny==4 and nx==4):
            continue
        elif v[ny][nx] == 'x':
            continue
        elif v[ny][nx] == 'o':
            if is_second_turn and (ny,nx) == j_pos:
                if left_app_count == 0:
                    answer += 1
                continue
            else: # 아무일 X (빈공간)
                continue

        # 이동 가능
        # 빈칸
        before_nynx = v[ny][nx]
        assert before_nynx == '.'
        v[ny][nx] = 'o'
        left_app_count -= 1
        if is_second_turn:
            h_pos = (ny,nx)
            dfs(not is_second_turn,j_pos[0],j_pos[1])
            h_pos = (cur_y,cur_x) # 원상 복구
        else:
            j_pos = (ny,nx)
            dfs(not is_second_turn,h_pos[0],h_pos[1])
            j_pos = (cur_y, cur_x) # 원상 복구
        left_app_count+=1  # 원상 복귀
        v[ny][nx] = before_nynx # 원상 복귀

dfs(False,0,0)
print(answer)


