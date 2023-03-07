import sys

n = int(input())
arr = list(map(int,input().split()))
mx = max(arr)

arr = list(map(lambda x : x/mx*100,arr))
avg = sum(arr)/len(arr)
print(avg)
