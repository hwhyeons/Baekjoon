import sys


n = int(input())
arr = []
for _ in range(n): 
    arr.append(int(input()))
    
is_seq_diff = False

diff = 0

if arr[2] - arr[1] == arr[1] - arr[0]:
    is_seq_diff = True
    diff = arr[2]-arr[1]
else:
    diff = arr[2]//arr[1]


ans = 0
# 등차 수열
if is_seq_diff:
    ans = arr[-1]+diff
else:
    ans = arr[-1]*diff
    
print(ans)
