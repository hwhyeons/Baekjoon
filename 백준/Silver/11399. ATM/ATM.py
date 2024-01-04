import itertools as e
a,b=eval("map(int,input().split()),"*2)
print(sum([*e.accumulate(sorted(b))]))