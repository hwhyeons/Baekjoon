import sys
input = sys.stdin.readline

d={}
def f(n):
    if n==1:
        return 1
    if n in d:
        return d[n]
    mx = n
    n = n*3+1 if n%2 else n//2
    mx = max(mx,f(n))
    return mx

t = int(input().rstrip())
for _ in range(t):
    n=int(input().rstrip())
    print(f(n))