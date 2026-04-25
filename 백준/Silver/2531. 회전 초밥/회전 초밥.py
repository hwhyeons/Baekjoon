
from collections import deque

max_ans = 0

N, D, K, C = map(int,input().split())
v: list[int] = []
for _ in range(N):
    v.append(int(input()))

# expand (순회를 쉽게 하기 위함)
v.extend(v[:])
d = deque()
m = dict()

m[-1] = 1
d.append(-1)
for i in range(K-1):
    d.append(v[i])
    if v[i] in m:
        m[v[i]] +=1
    else:
        m[v[i]] = 1

for i in range(len(v)-K+1):
    rm:int = d.popleft()
    new_num: int = v[i+K-1]
    d.append(new_num)
    m[rm] -= 1
    if m[rm] == 0:
        m.pop(rm)

    if new_num in m:
        m[new_num] +=1
    else:
        m[new_num] = 1

    if C not in m:
        max_ans = max(max_ans,len(m)+1)
    else:
        max_ans = max(max_ans, len(m))

print(max_ans)