

tcnt = int(input())
for _ in range(tcnt):
    n = int(input())
    ans = 0
    cur = 0
    for i in range(n):
        a,b = map(int,input().split())
        cur = cur + a - b
        ans = min(cur,ans)
    print(abs(ans))


