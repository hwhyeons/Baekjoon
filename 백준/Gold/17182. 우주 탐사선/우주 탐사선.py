import math
import itertools
N,K= map(int,input().split())
v = []
for _ in range(N):
    v.append(list(map(int,input().split())))


# dist = [[math.inf for _ in range(N)] for _ in range(N)]
dist =  v.copy()
for i in range(N):
    for j in range(N):
        for k in range(N):
            dist[i][k] = min(dist[i][j]+dist[j][k],dist[i][k])

lst = [i for i in range(N)]
lst.remove(K)
it = itertools.permutations(lst)
answer = math.inf
while val:=next(it,None):
    acc = 0
    acc += dist[K][val[0]]
    for i in range(0,N-2):
        acc += dist[val[i]][val[i+1]]
    answer = min(answer,acc)
print(answer)
