import itertools
print(10+sum(map(lambda x : 5 if x[0]==x[1] else 10,itertools.pairwise(input()))))
