v=open(0).read().split()
c={*v[1:(n:=int(v[0]))+1]}
for i in range(n+1):
    if v[i] == '?':
        f=v[i-1][-1] if i>1 else 0
        l=v[i+1][0] if i!=n else 0
print(*[s for s in v[n+2:] if (s[0]==f or f==0) and (s[-1]==l or l==0) and s not in c])