tcnt = int(input())
for _ in range(tcnt):
    a,b = input().split()
    print(len(a.replace(b,"&")))

