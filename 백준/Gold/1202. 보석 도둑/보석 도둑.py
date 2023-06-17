import sys
import heapq
input = sys.stdin.readline


n,k = map(int,input().split())


mv = []
bags = []
for i in range(n):
    m,v = map(int, input().split())
    heapq.heappush(mv,(m,-v))
for i in range(k):
    heapq.heappush(bags,int(input()))

cur = []
ans = 0
while len(bags) > 0:
    bagW = heapq.heappop(bags)
    # 해당되는 무게 전부 추가
    while len(mv) > 0:
        m,v = heapq.heappop(mv)
        if m <= bagW:
            heapq.heappush(cur,(v,m))
        else:
            heapq.heappush(mv,(m,v))
            break

    if len(cur) > 0:
        ans += (-heapq.heappop(cur)[0])

print(ans)





