import itertools
import functools
N,M = map(int,input().split())
v= list(map(int,input().split()))
print(min(filter(lambda k : k<=M,map(sum,itertools.combinations(v,3))),key=functools.cmp_to_key(lambda x,y:abs(x-M)-abs(y-M))))