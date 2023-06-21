from functools import reduce
import math

a,p = map(int,input().split())
d = dict()
d[a] = 0
before:str = str(a)
while True:
    acc = int(reduce(lambda x1,x2 : x1 + math.pow(int(x2),p),before,0))
    if acc in d:
        print(d[acc])
        break
    else:
        d[acc] = len(d)
        before:str = str(acc)
