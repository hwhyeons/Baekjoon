s=[*open(0)]
print(*map(lambda x:["?",x[0]][len({*x})<2],zip(*s[1:])),sep="")