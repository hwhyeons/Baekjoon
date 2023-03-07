import sys

n = int(input())
for _ in range(n):
    tmp = input().split()
    a = int(tmp[0])
    b = list(tmp[1])
    s = ""
    for i in b:
        s += i*a
    print(s)
    
    
