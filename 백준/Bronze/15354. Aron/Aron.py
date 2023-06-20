import itertools
print(len([i for i, j in itertools.groupby([input() for _ in range(int(input()))])])+1)