from collections import deque

ar = [0,1,0,1,2,1,0,1,2,3,2,1,0,1,2,3,4,3,2,1]
d = deque(ar)
n = int(input())
while True:
    if n == 0:
        break
    elif n < 5:
        if d[0] == 0:
            d.rotate(-1)
        elif d[1] > d[0]: # 증가하는 방향
            d.rotate(-1)
        break
    n -= 5
    d.rotate(-1)

print(d[0])



