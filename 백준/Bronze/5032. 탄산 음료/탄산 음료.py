a,b,c = map(int,input().split())
cur = a+b
ans = 0
while cur>=c:
    ans += cur//c
    cur = cur%c + cur//c
print(ans)
