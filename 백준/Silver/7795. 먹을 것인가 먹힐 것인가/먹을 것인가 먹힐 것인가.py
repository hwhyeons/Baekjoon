tcnt = int(input())
for t_ in range(tcnt):
    a,b = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    arr2 = list(map(int, input().split()))
    arr2.sort()
    ans = 0
    idxB = 0
    for idxA in range(len(arr)):
        aVal = arr[idxA]
        while True:
            if idxB >= len(arr2):
                break
            if arr2[idxB] >= aVal:
                break
            idxB+=1
        ans += idxB
    print(ans)
# 1 1 3 7 8
# 1 3 6




