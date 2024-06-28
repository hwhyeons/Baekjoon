N = int(input())
v = list(map(int, input().split()))
cnt = [0]*(1000001)
for val in v:
    cnt[val] += 1

answer = []
answer.append(-1)
stack = []
stack.append((v[-1],cnt[v[-1]]))
for idx in range(N-2,-1,-1):
    want_min = cnt[v[idx]]+1
    tf_find = False
    while stack:
        top = stack[-1]
        stack.pop(len(stack)-1)
        top_number = top[0]
        top_value = top[1]
        if top_value < want_min:
            continue
        # 되는 경우
        tf_find = True
        stack.append((top_number,top_value))
        answer.append(top_number)
        break
    if not tf_find:
        answer.append(-1)
    stack.append((v[idx],cnt[v[idx]]))
print(*reversed(answer),sep=' ')
# min_arr = [0]*N
# for i in range(len(min_arr)):
#     min_arr[i] = min(min_arr[i-1],cnt[i])