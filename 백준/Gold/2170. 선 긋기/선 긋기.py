n= int(input())
v=sorted([tuple(map(int, input().split())) for _ in range(n)])
acc=(b:=v[0][1])-v[0][0]
for p in v:
    s,e=p
    if s<b:
        acc += e-b if e>b else 0
        b=max(b,e)
    else:
        acc+=e-s
        b=e
print(acc)