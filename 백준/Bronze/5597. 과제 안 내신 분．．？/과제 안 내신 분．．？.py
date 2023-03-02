import sys

list = list(range(1,31))

for _ in range(28):
    rm = int(input())
    list.remove(rm)
    
print(min(list))
print(max(list))

