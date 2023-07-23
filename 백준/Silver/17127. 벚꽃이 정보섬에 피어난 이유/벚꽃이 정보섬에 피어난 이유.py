import functools as f
n = int(input())
v = list(map(int,input().split()))
ans = -1
for a in range(1,n-2):
    for b in range(a+1,n-1):
        for c in range(b+1,n):
            ans = max(ans, sum(list(map(lambda x: f.reduce(lambda x1, x2: x1 * x2, x, 1), [v[0:a], v[a:b], v[b:c], v[c:]]))))
print(ans)