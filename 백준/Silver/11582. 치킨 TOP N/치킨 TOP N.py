N = int(input())
v = list(map(int, input().split()))
K = int(input())
t = N//K
for i in range(0,N,t):
    print(*sorted(v[i:i+t]),sep=" ",end=" ")