import sys

while True:
    s = input()
    if s == "#":
        break
    key = s[0]
    key_low = s[0].lower()
    key_upper = s[0].upper()
    ans = s[2:].count(key_low) + s[2:].count(key_upper)
    print(key,ans)
    
    