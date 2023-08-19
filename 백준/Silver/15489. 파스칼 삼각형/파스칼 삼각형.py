import functools

@functools.cache
def f(r,c):
    if r==1 or c==1 or c==r:
        return 1
    return f(r-1,c-1)+f(r-1,c)

r,c,w=map(int,input().split())
acc = 0
for i in range(w):
    for j in range(i+1):
        acc+=f(r+i,c+j)
print(acc)