import itertools
import collections

n = int(input())
v = [i**3 for i in range(1,n) if i**3 <= n]
f = list(filter(lambda x: x <= n, map(lambda x: x[0] + x[1], itertools.combinations(v, 2))))
c = collections.Counter(f)
l = list(filter(lambda x: x[1] == 2, c.items()))
if len(l) == 0:
    print("none")
else:
    print(max(l,key=lambda x:x[0])[0])



