from itertools import accumulate
import sys
input = sys.stdin.readline
N,M = map(int,input().split())
l = list(accumulate(map(int,input().split())))
l.insert(0,0)
for _ in range(M):
    i,j = map(int,input().split())
    print(l[j]-l[i-1])



