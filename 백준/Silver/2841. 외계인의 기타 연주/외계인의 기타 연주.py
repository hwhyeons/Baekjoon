N,P = map(int,input().split())
d: dict[int,list[int]] = dict()
ans = 0
for _ in range(N):
    a,b = map(int,input().split())
    if a not in d:
        d[a] = []
    stack = d[a]
    while stack:
        if stack[-1] > b:
            ans+=1
            stack.pop()
            continue
        break

    # 이미 눌려있는 경우
    if stack and stack[-1] == b:
        pass
    else:
        # 안눌려져있는 경우
        ans+=1
        stack.append(b)
print(ans)