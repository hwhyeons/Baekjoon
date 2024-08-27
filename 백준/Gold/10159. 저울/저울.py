import math
N = int(input())
M = int(input())
d = [[math.inf for j in range(N+1)] for i in range(N+1)]
for _ in range(M):
    a,b = map(int,input().split())
    d[a][b] = 1

for i in range(1,N+1):
    for j in range(1,N+1):
        for k in range(1,N+1):
            d[j][k] = min(d[j][i]+d[i][k],d[j][k])

for i in range(1,N+1):
    ans = 0
    for j in range(1,N+1):
        if i == j:
            continue
        if d[i][j] < 1000000 or d[j][i] < 1000000:
            ans+=1
    print(N-1-ans)




