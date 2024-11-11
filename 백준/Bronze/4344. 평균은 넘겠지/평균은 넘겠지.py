tcnt = int(input())
for _ in range(tcnt):
    v=list(map(int,input().split()[1:]))
    avg=sum(v)/len(v)
    cnt=sum(1 if i>avg else 0 for i in v)
    print("{:.3f}%".format(cnt/len(v)*100))