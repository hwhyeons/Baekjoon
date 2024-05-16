import graphlib
N,M=map(int,input().split())
d={k:set() for k in range(1,N+1)}
for _ in range(M):
    a,b=map(int,input().split())
    d[b].add(a)
gp=graphlib.TopologicalSorter(d)
print(*gp.static_order())