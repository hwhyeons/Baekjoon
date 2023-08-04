while True:
    a,b = map(int,input().split())
    if a*b==0:
        break
    print("factor" if b%a==0 else "multiple" if a%b==0 else "neither")