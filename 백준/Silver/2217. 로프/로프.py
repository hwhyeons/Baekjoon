v = sorted([int(input()) for _ in range(int(input()))])
i = 0
ans = -1
for w in range(1,100001):
    ans = max(ans,w*(len(v)-i))
    if w == v[i]:
        while True:
            i += 1
            if i == len(v):
                print(ans)
                exit(0)
            elif w!=v[i]:
                break
print(ans)