input()
v=[sorted(map(int,input().split()),reverse=True) for _ in range(3)]
print(sum(v[0])+sum(v[1])+sum(v[2]))
m=min(len(v[0]),len(v[1]),len(v[2]))
s0=sum(v[0][:m])*0.9 + (sum(v[0][m:]) if len(v[0]) > m else 0)
s1=sum(v[1][:m])*0.9 + (sum(v[1][m:]) if len(v[1]) > m else 0)
s2=sum(v[2][:m])*0.9 + (sum(v[2][m:]) if len(v[2]) > m else 0)
print(int(s0+s1+s2))