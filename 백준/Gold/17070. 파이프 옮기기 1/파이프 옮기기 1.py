# class Pipe:
#     dir: str

# ans = 0
dp: dict[tuple[int,int,str],int] = dict()

N = int(input())
v = []
for _ in range(N):
    v.append(list(map(int,input().split())))


def dfs(y: int, x: int,dir: str) -> int:
    # dir : 들어오는 방향
    global dp
    if (y,x,dir) in dp:
        return dp[(y,x,dir)]
    if y>=N or x>=N or y<0 or x<0:
        return 0
    if v[y][x] == 1:
        return 0
    if dir=="c" and (v[y][x-1] ==1 or v[y-1][x] == 1):
        return 0
    elif dir=="r" and v[y][x-1]==1:
        return 0
    elif dir=="d" and v[y-1][x] == 1:
        return 0

    local_ans = 0
    if dir=="r": # 오른쪽 방향으로 들어오는 경우
        a1=dfs(y,x-1,"r")
        a2=dfs(y,x-1,"c")
        local_ans+=a1+a2
    elif dir=="d":
        a1=dfs(y-1,x,"d")
        a2=dfs(y-1,x,"c")
        local_ans+=a1+a2
    else:
        # 대각선으로 오는 경우
        a1=dfs(y-1,x-1,"d")
        a2=dfs(y-1,x-1,"r")
        a3=dfs(y-1,x-1,"c")
        local_ans+=a1+a2+a3
    dp[(y,x,dir)] = local_ans
    return local_ans





# print(dfs(1,2,"c"))
dp[(0,1,"r")] = 1
ans1 = dfs(N-1,N-1,"r")
ans2 = dfs(N-1,N-1,"d")
ans3 = dfs(N-1,N-1,"c")
print(ans1+ans2+ans3)