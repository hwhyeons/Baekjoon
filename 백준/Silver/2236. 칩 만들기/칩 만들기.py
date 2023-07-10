
N,K = map(int,input().split())
v = list(map(int, input().split()))
vc = [(-val,idx) for idx,val in enumerate(v)]

vc.sort()
ans1 = list()
ans2 = [0]*N
for i in range(min(N,K)):
    ans1.append(vc[i][1]+1)
    ans2[vc[i][1]] = vc[i][1]+1


print(*sorted(ans1),sep="\n")
if K > N:
    print("0\n"*(K-N),end="")
print(*ans2,sep="\n")





