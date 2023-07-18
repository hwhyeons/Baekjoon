import itertools
print(sum(int(i[0])*int(i[1]) for i in itertools.product(*map(lambda x : [*x],input().split()))))