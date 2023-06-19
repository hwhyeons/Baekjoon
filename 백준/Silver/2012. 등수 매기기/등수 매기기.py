n = int(input())
v = []
for i in range(n):
    v.append(int(input()))

v.sort()
ans = 0
for cur in range(1,n+1):
    ans += abs(cur-v[cur-1])
print(ans)

