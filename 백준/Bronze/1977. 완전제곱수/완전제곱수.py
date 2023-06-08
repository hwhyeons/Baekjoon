import math

m = int(input())
n = int(input())

acc = 0
mn = -1
for i in range(m, n + 1):
    tmp = math.isqrt(i)
    if tmp * tmp == i:
        acc += i
        mn = i if mn == -1 else mn

if mn == -1:
    print(-1)
else:
    print(acc)
    print(mn)
