import math as m
t=True
f=False
for _ in range(int(input())):
    s = (v:=input().split())[0]
    N,T,L=map(int,v[1:])
    k=100000000*L
    if s=="O(N)":
        tf = t if N*T<=k else f
    elif s=="O(2^N)":
        tf = t if N<=m.log2(k/T) else f
    elif s[:4]=="O(N^":
        tf = t if T*N**int(s[4])<=k else f
    else:
        tf = f if N>=13 else (t if m.factorial(N)*T<=k else f)
    print("May Pass." if tf else "TLE!")