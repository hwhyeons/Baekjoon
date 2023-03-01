import sys

c = int(input())
a,b = map(int,input().split())

count = a//2 + b
print(min(count,c))


