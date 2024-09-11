tcnt = int(input())
for _ in range(tcnt):
    N = int(input())
    v = []
    for _ in range(N):
        v.append((*map(int,input().split()),))
    v.sort()
    min_val = 10000000
    answer = 0
    for tp in v:
        if tp[1] < min_val:
            answer+=1
            min_val = tp[1]
    print(answer)

