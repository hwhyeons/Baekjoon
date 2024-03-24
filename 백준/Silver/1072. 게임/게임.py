import math

X,Y = map(int,input().split())
if Y==X:
    print(-1)
    exit(0)
s=1
e=20000000000

Z = int((Y*100)/X)
if Z >= 99:
    print(-1)
    exit(0)

start_z = Z

min_answer = math.inf
before_shrink = False # 처음에는 무조건 늘림
while s<=e:
    m = (s+e)//2
    cur_up = Y+m # 분자
    cur_down =X+m # 분모
    cur_z = int((cur_up*100/cur_down))
    if cur_z == start_z:
        s = m +1
    else:
        e = m -1
        min_answer = min(min_answer, m)


print(min_answer)

