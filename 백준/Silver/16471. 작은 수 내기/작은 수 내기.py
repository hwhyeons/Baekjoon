n=int(input())
v1 = list(sorted(map(int, input().split())))
acc = 0
it = iter(list(sorted(map(int, input().split()))))
for val in v1:
    while True:
        nv = next(it,None)
        if nv is None:
            break
        if val < nv:
            acc+=1
            break
print("YES" if acc>=(n+1)//2 else "NO")