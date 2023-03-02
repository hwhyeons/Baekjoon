import sys

b_count,N = map(int,input().split())

lst = list(range(1,b_count+1))

for _ in range(N):
    i,j = map(int,input().split())
    i -= 1
    j -= 1
    tmp = lst[i]
    lst[i] = lst[j]
    lst[j] = tmp

print(" ".join(list(map(str,lst))))
