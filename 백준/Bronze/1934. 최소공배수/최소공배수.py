import math
print(*[math.lcm(*map(int,input().split())) for _ in range(int(input()))],sep="\n")