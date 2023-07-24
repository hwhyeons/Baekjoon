n=int(input())
v=map(int,input().split())
import itertools
p = itertools.pairwise(v)
flag = True
for i,j in p:
    if j==i or max(j,i) > n:
        print("NO")
        exit(0)
    if flag:
        flag = j > i
    elif not flag and j < i:
        pass
    else:
        print("NO")
        exit(0)
print("YES")