import sys

ans = 0
r_ans = 0
count = int(input())
for _ in range(count):
    lst = list(map(int,sys.stdin.readline().split()))
    arr = list(map(int,set(lst)))
    if len(arr) == 3:
        ans = 100*max(arr)
    elif len(arr) == 2:
        if lst.count(arr[0]) == 2:
            ans = 1000+100*(int(arr[0]))
        else:
            ans = 1000+100*(int(arr[1]))
    else: # 같은 눈 3개
        ans = 10000+arr[0]*1000
    r_ans = max(r_ans,ans)
    
print(r_ans)
    

