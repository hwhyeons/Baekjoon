N = int(input())
v = [[' ']*N for _ in range(N)]

def dfs(p, y, x):
    global v
    # p : ()^2 형태의 수
    # y,x : 사각형의 우측하단 좌표
    dv=p//3 # N이 27이면 dv는 9
    if p == 3:
        v[y][x]='*'
        v[y][x-1]='*'
        v[y][x-2]='*'
        v[y-2][x]='*'
        v[y-2][x-1]='*'
        v[y-2][x-2]='*'
        v[y-1][x]='*'
        v[y-1][x-2]='*'
        return

    dfs(dv,y-2*dv,x-2*dv) # 왼쪽 위
    dfs(dv,y-2*dv,x-dv) # 위
    dfs(dv,y-2*dv,x) # 오른쪽 위
    dfs(dv,y-dv,x) # 오른쪽
    dfs(dv,y,x) # 오른쪽 아래
    dfs(dv,y,x-dv) # 아래
    dfs(dv,y,x-2*dv) # 아래 왼쪽
    dfs(dv,y-dv,x-2*dv) # 왼쪽


dfs(N,N-1,N-1)
for i in range(N):
    for j in range(N):
        print(v[i][j],end='')
    print()