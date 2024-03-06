n = int(input())
v = []
for _ in range(n):
    f = float(input())
    v.append(f)
if n == 1:
    print('{:.3f}'.format(v[0]+0.0000001))
    exit(0)

mx = 0
acc = 0.0
for e in v:
    if e == 0.0:
        acc = 0
        continue
    if e >= 1.0:
        mx = max(mx, e)
        if acc == 0:
            acc = e
        else:
            if acc < 1.0:
                acc = e
            else:
                acc *= e
        mx = max(mx,acc)
    else: # e < 1
        mx = max(mx, e)
        if acc < 1.0:
            acc = e
        else:
            acc *= e
        mx = max(mx,acc)

# print(round(mx,3))
print('{:.3f}'.format(mx+0.0000001))

