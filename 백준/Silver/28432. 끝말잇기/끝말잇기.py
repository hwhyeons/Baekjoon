v=open(0).read().split()
n= int(v[0])
first,last = 0,0
c={*v[1:n+1]}
for i in range(1,n+1):
    if v[i] == '?':
        first=v[i-1][-1] if i>1 else 0
        last=v[i+1][0] if i!=n else 0
# print(first,last)
print(*[s for s in v[n+2:] if (s[0]==first or first==0) and (s[-1]==last or last==0) and s not in c])