import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
d = dict()

def find(num: int) -> int:
    # find parent
    global d
    # self return (parent finish)
    if num not in d or d[num] == num:
        d[num] = num
        return num
    parent = d[num]
    d[num] = find(parent)
    return d[num]


def union_optimize(num1: int, num2: int):
    global d
    parent1 = find(num1)
    parent2 = find(num2)
    if parent1 < parent2:
        d[parent1] = parent2
    else:
        d[parent2] = parent1


n,m = map(int,input().split())
for i in range(m):
    a,b = map(int,input().split())
    if find(a) == find(b):
        print(i+1)
        exit(0)
    else:
        union_optimize(a,b)
print(0)

