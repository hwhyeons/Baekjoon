v=sorted([tuple(map(int, input().split())) for _ in range(int(input()))])
c= (b:=v[0][1]) - v[0][0]
for p in v:
    s,e=p
    c+= max(e-b,0) if s<b else e-s
    if s<b:
        b=max(b,e)
    else:
        b=e
print(c)
