a,b,c=map(int,input().split())
l,j,k=map(int,input().split())
ratio=min(a/l,b/j,c/k)
print(a-l*ratio,b-j*ratio,c-k*ratio)