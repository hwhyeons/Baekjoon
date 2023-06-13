n,m,k = map(int,input().split())
if n + m -1 > k:
    print("NO")
else:
    print("YES")
    for i in range(n):
        for j in range(i+1,i+1+m):
            print(j,end=' ')
        print()