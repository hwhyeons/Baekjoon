import sys
sys.setrecursionlimit(10000000)
MAX = 210000000

N,D = map(int,input().split())

short_path: dict[int,list[tuple[int,int]]] = dict() # key: 도착지점 / value : (시작지점,거리)
dp = dict() # dict[int,int]
for _ in range(N):
    a,b,c = map(int,input().split())
    if b not in short_path:
        short_path[b] = []
    short_path[b].append((a,c))

def dfs(num):
    if num in dp:
        return dp[num]
    if num < 0:
        return MAX
    if num == 0:
        return 0

    ans1 = 1+dfs(num-1) # 방법1 : 바로 이전

    # 방법2 : 지름길
    if num in short_path:
        for tp in short_path[num]:
            start_point = tp[0]
            value = tp[1]
            ans1 = min(ans1,dfs(start_point)+value)
    dp[num] = ans1
    return ans1


print(dfs(D))
