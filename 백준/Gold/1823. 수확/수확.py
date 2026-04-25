import sys
sys.setrecursionlimit(5000)
N = int(input())
v = []
for _ in range(N):
    v.append(int(input()))

dps =[[0 for i in range(N)] for i in range(N)]
def dp(left: int, right: int, cnt: int):
    global v,dps
    if left == right:
        return cnt*v[left]
    if dps[left][right]:
        return dps[left][right]

    rt = max(dp(left+1,right,cnt+1) + cnt*v[left],dp(left,right-1,cnt+1) + cnt*v[right])
    dps[left][right] = rt
    return rt
print(dp(0,N-1,1))

