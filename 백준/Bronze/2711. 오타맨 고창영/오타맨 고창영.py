import sys

n = int(input())
for i in range(n):
    l = sys.stdin.readline().split()
    a = int(l[0])
    b = l[1]
    s = b[:a-1]+b[a:]
    print(s)
