d={1:1}
def f(n):
    if n in d:
        return d[n]
    d[n] = max(n,f(n*3+1 if n%2 else n//2))
    return d[n]

v = map(int,open(0).read().split()[1:])
[print(f(i)) for i in v]
