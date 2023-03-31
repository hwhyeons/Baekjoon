def fact(num):
    if num == 0:
        return 0
    elif num == 1:
        return 1
    elif num == 2:
        return 2
    else:
        return num*fact(num-1)


n,r = map(int,input().split())
ans = fact(n)//(fact(r)*fact(n-r))
print(ans)

