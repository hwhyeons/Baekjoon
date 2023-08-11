r,b=map(int,input().split())
acc = r+b
for w in range(1,acc):
    if acc%w !=0:
        continue
    h = acc//w
    if (w-2)*(h-2) == b:
        print(h,w)
        break
