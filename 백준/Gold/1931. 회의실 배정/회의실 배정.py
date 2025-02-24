
N = int(input())
v = []
for _ in range(N):
    a,b = map(int,input().split())
    v.append((a,b))
v.sort()

ans = 0
end = 0
for i in range(len(v)):
    s,e = v[i]
    if end == 0 or s>=end:
        ans += 1
        end = e
    if e<end:
        end = e
    continue
print(ans)