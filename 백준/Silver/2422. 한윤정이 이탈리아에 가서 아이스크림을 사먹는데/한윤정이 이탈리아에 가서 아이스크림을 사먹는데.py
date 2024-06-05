import math
import itertools
N,M = map(int,input().split())
banned = set()
if N <= 2:
    print(0)
    exit(0)

for _ in range(M):
    banned.add(tuple(sorted(list(map(int, input().split())))))

cnt = 0
for case in itertools.combinations([i for i in range(1,N+1)],3):
    s = sorted(case)
    if (s[0],s[1]) in banned or (s[1],s[2]) in banned or (s[0],s[2]) in banned:
        continue
    cnt+=1

print(cnt)