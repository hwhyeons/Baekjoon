t = int(input())
for _ in range(t):
    n=int(input())
    mx = n
    while n != 1:
        n = n*3+1 if n%2 else n//2
        mx=max(mx,n)
    print(mx)