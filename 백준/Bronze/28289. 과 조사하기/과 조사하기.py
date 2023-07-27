n = int(input())
v = [tuple(map(int, input().split())) for _ in range(n)]
ans=[0]*4
for i in v:
    if i[0]==1:
        ans[3]+=1
    elif i[1] < 3:
        ans[0]+=1
    else:
        ans[i[1]-2]+=1
print(*ans,sep='\n')
