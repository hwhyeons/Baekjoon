tcnt = int(input())
for i in range(tcnt):
    lst = list(filter(lambda x: x%2==0,map(int,input().split())))
    print(sum(lst),min(lst))