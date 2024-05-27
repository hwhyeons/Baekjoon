import sys
input = sys.stdin.readline
N,M = map(int,input().split())
v = []
for _ in range(N):
    v.append(list(map(int,input().split())))
# 미리 계산
acc = []
acc.append([0 for _ in range(N+1)])
for i in range(1,N+1):
    acc.append([0 for _ in range(N + 1)])
    cur_line_acc = 0
    for j in range(1,N+1):
        acc[i][j] = v[i-1][j-1] + acc[i-1][j] + cur_line_acc
        cur_line_acc += v[i-1][j-1]

for _ in range(M):
    y1,x1,y2,x2 = map(int,input().split())
    print(acc[y2][x2]-acc[y1-1][x2]-(acc[y2][x1-1]-acc[y1-1][x1-1]))