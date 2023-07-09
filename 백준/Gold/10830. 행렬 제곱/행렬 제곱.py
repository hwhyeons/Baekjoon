from functools import cache
from typing import List, Dict
import sys
# sys.setrecursionlimit(10**6)
# 메모리 초과 -> pypy 대신 python / recursionlimit 제한 하기
# print = sys.stdout.write  # write는 큰 영향 없음
# input = sys.stdin.readline


N,B = map(int,input().split())
v = [list(map(int,input().split())) for _ in range(N)]


# 곱 행렬 리턴
def multiply(a,b) -> List[list]:
    global N
    new_m = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            new_m[i][j] = 0
            for k in range(N):
                new_m[i][j] += a[i][k] * b[k][j]
                new_m[i][j]%=1000
    return new_m

d:Dict[int,list[list]] = dict() # key : 제곱값 / val : 행렬을 포함하는 리스트
# a 행렬을 exp번 제곱
def matrix(a,exp):
    global d
    if exp in d:
        return d[exp]
    elif exp == 1:
        return a
    elif exp%2 == 0:
        new_matrix1 = matrix(a,exp//2)
        d[exp] = multiply(new_matrix1,new_matrix1)
        return d[exp]
    else:
        new_matrix1 = matrix(a,exp//2)
        new_matrix2 = matrix(a,exp//2+1)
        d[exp] = multiply(new_matrix1,new_matrix2)
        return d[exp]


mat = matrix(v,B)
for line in mat:
    line = map(lambda x : x%1000,line)
    print(*line,sep=" ")
