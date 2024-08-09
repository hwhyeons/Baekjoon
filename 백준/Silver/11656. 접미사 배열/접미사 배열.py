s=input()
lst = [s[i:] for i in range(len(s))]
print(*sorted(lst),sep='\n')