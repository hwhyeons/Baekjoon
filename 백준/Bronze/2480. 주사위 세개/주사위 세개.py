
a,b,c = map(int,input().split())

ans = 0
if a == b == c:
    ans = 10000+1000*a
elif a==b and b!=c:
    ans = 1000+100*a
elif a==c and a!=b:
    ans = 1000+100*a
elif b==c and a != b:
    ans = 1000+100*b
elif a!=b and b!=c and a!=c:
    ans = max(a,b,c)*100

print(ans)


