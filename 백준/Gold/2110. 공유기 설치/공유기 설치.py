import math

N,C = map(int,input().split())
v = []
for _ in range(N):
    v.append(int(input()))
v.sort()

# 거리 배열
dist_arr: list[tuple[int,int,int]] = []  # 좌표1,좌표2,거리값
for i in range(len(v)-1):
    dist_arr.append((v[i],v[i+1],v[i+1]-v[i]))

left = 0
right = abs(v[0]-v[-1])

max_min = -1
while left <= right:
    mid: int = (left+right)//2
    acc = 0
    ok_cnt = 0
    for d in dist_arr:
        acc += d[2]
        if acc < mid:
            continue
        # 통과
        acc = 0 # acc 초기화
        ok_cnt = ok_cnt + 1 if ok_cnt!=0 else ok_cnt + 2
        if ok_cnt == C:
            max_min = max(max_min,mid)
            break
    # 값이 너무 큰 경우 -> 값 축소
    if ok_cnt < C:
        right = mid - 1
    else:
        left = mid + 1

print(max_min)