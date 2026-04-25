import itertools

tcnt = int(input())
for i in range(1,tcnt+1):
    n = input()
    if int(n) == 0:
        print("Case #{}: {}".format(i,"INSOMNIA"))
        continue
    s = set()
    cur = int(n)
    j = 0
    while True:
        j+=1
        s = s.union(set(str(cur)))
        if len(s) == 10:
            print("Case #{}: {}".format(i, cur))
            break
        else:
            cur = int(n)*(j+1)

