import sys

while True:
    s1 = input()
    if s1 == "0":
        break
    s2 = s1[::-1]
    if s1 == s2:
        print("yes")
    else:
        print("no")
    
