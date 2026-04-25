s = input()
v = [s[i:i+3] for i in range(len(s))]
print(v.count('JOI'),v.count('IOI'),sep="\n")