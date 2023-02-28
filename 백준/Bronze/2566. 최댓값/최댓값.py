import sys


arr = []
for _ in range(9):
    arr.append(list(map(int,sys.stdin.readline().split(" "))))

mx = 0
my = 0
for i in range(9):
    for j in range(9):
        if arr[i][j] > arr[my][mx]:
            my = i
            mx = j

print(arr[my][mx])
print(my+1,mx+1)
        
    

