import sys

a,b = map(int,input().split())
arr = list(map(int,input().split()))

s = ""
for i in list(filter(lambda x : x < b , arr)):
    s += str(i) +" "
    
print(s)




