import sys

b_count,N = map(int,input().split())

lst = []
for i in range(b_count):
    lst.append(0)

for i in range(N):
    a,b,c = map(int,input().split())
    for j in range(a,b+1):
        lst[j-1] = c

s = ""
for i in range(len(lst)):
    s+=str(lst[i])+" "

print(s)
        

