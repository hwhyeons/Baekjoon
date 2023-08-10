import itertools as t
n,k = map(int,input().split())
v=[int(input()) for _ in range(n)]
p=t.pairwise(v)
print(sum(1 for a,b in p if a-b>=k))