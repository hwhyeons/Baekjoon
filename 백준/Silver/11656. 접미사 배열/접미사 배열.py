s=input()
print(*sorted([s[i:] for i in range(len(s))]))