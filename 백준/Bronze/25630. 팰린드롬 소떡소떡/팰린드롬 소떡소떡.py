import math
n = int(input())
line = input()
m1 = int(math.floor(len(line)//2))  
m2 = int(math.floor(len(line)/2+0.5))
s1 = line[:m1]
s2 = line[m2:][::-1]
print(len(list(filter(lambda x : len(set(x))==2, zip(s1,s2)))))

