a,b,c,l,j,k=map(int,open(0).read().split())
print(a-l*(r:=min(a/l,b/j,c/k)),b-j*r,c-k*r)