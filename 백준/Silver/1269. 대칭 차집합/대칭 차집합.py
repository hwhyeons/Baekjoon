import sys

input()
# a,b = map(int,sys.stdin.readline().split())
a = set(input().split())
b = set(input().split())
print(len(a-b)+len(b-a))

