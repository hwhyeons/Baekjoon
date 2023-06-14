import sys

sys.setrecursionlimit(10**6)

n,m = map(int,input().split())
v = [list(map(int,input().split())) for _ in range(n)]
dp = [[0]*(m+1) for _ in range(n+1)]
for row in range(1,n+1):
    for col in range(1,m+1):
        dp[row][col] = v[row-1][col-1] + max(dp[row-1][col],dp[row-1][col-1],dp[row][col-1])

print(dp[n][m])
