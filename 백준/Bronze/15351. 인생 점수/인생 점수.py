import functools as f
for i in range(int(input())):
    k=f.reduce(lambda a,b:a+ord(b)-64,input().replace(" ",""),0)
    print("PERFECT LIFE" if k==100 else k)