import graphlib
N,M=map(int,input().split())
d={k:set() for k in range(1,N+1)}
for _ in range(M):
    a,b=map(int,input().split())
    d[b]|={a}
print(*graphlib.TopologicalSorter(d).static_order())