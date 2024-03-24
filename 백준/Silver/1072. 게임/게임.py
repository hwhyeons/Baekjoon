import math

X,Y = map(int,input().split())
if Y==X:
    print(-1)
    exit(0)
s=1
e=20000000000

Z = int(Y/X*100+0.0000000000001)
if Z >= 99:
    print(-1)
    exit(0)

start_z = Z

min_answer = math.inf
while s<=e:
    m = (s+e)//2
    cur_up = Y+m # 분자
    cur_down =X+m # 분모
    cur_z = int(cur_up/cur_down*100+0.0000000000001)
    if cur_z == start_z:
        s = m +1
    else:
        e = m -1
        min_answer = min(min_answer, m)

print(min_answer)

