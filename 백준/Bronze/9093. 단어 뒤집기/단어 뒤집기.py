import sys
c = int(input())
for _ in range(c):
    s = input().split()
    strs = ""
    for j in s:
        strs += j[::-1]+" "
    print(strs)

    
