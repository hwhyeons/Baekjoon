
n = int(input())
v = [tuple(map(int, input().split())) for _ in range(n)]
mx = max(v, key=lambda x: x[0])[0]
ans = 0
max_val = -1000000000
for price in range(0,mx+1):
    tmp = 0
    for p in v:
        pr = p[0]
        b = p[1]
        if pr >= price:
            if price - b > 0:
                tmp += price - b
    if tmp > max_val:
        ans = price
        max_val = tmp
if max_val < 0:
    print(0)
else:
    print(ans)