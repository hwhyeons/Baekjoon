for _ in range(int(input())):
    a=sum(v:=list(map(int,input().split()[1:])))/(k:=len(v))
    print("{:.3f}%".format(sum(1 for i in v if i>a)/k*100))