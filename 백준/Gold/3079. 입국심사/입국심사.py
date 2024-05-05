import math

N,M = map(int,input().split())
v = [int(input()) for _ in range(N)] # 심사대

max_test = 100000000000000000000
s = 0
e = max_test

answer = math.inf
while s <= e:
    m = (s+e)//2
    # 개수 계산
    acc = 0
    for time_ in v:
        acc += m//time_
        if acc >= M:
            break
    if acc < M: # 최대 심사 인원수보다 적은 경우
        s = m+1
    else:
        answer = min(answer, m)
        e = m -1
if answer >= max_test:
    raise Exception("max error")

print(answer)


