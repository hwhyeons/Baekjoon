from collections import defaultdict
N,M = map(int,input().split())
d=defaultdict(lambda : defaultdict(int))
for _ in range(N):
    for j,c in enumerate(input()):
        d[j][c]+=1
acc=0
for i in range(M):
    max_char,cnt = min(d[i].items(),key=lambda x:(-x[1],x[0]))
    acc+=N-cnt
    print(max_char,end='')
print(f"\n{acc}")