r,b=map(int,input().split())
acc = r+b
for w in range(1,acc):
    if acc%w ==0 and (w-2)*((h:=acc//w)-2)==b:
        print(h,w)
        break