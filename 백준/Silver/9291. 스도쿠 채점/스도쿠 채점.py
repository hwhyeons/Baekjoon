tcnt = int(input())
for o in range(tcnt):
    if o!=0:
        input()
    v = [list(input().split()) for _ in range(9)]
    t1 = True
    for i in range(9):
        if len(set(v[i])) != 9:
            t1 = False
    # t1 = all(len(set(i))==9 for i in v)
    # t2 = all(len(set([v[row][col] for col in range(9)]))==9 for row in range(9))
    t2 = True
    for i in range(9):
        s = set()
        for row in range(9):
            s.add(v[row][i])
        if len(s) != 9:
            t2 = False
            break
    t3 = True
    for i in range(0,9,3):
        tmp = v[i:i+3]
        for j in range(0,9,3):
            s = set()
            for k in range(3):
                for m in range(3):
                    s.add(tmp[k][j+m])
            if len(s) != 9:
                t3 = False
                break
    if t1 and t2 and t3:
        print(f"Case {o+1}: CORRECT")
    else:
        print(f"Case {o+1}: INCORRECT")
