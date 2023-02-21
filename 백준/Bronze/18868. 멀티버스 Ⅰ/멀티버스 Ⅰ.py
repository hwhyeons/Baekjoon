import sys

M,N = map(int,sys.stdin.readline().split()) # 한 줄 스킵

arr = []

ans = 0

for i in range(M):
    arr.append(list(map(int,sys.stdin.readline().split())))

for i in range(M):
    for j in range(i+1,M):
        gap1 = None
        gap2 = None
        ok = True
        for k in range(N-1):
            for k2 in range(k+1,N):
                gap1 = arr[i][k]-arr[i][k2]
                gap2 = arr[j][k]-arr[j][k2]
                if gap1 == gap2 or gap1*gap2 > 0:
                    continue
                else:
                    ok = False
                    break
        if ok:
            ans+=1
print(ans)




