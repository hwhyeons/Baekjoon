import sys
# sys.setrecursionlimit(10**6)
# 메모리 초과 -> pypy 대신 python / recursionlimit 제한 하기
input = sys.stdin.readline
s = input().rstrip("\n")
di = {"A":3,"B":2,"C":1,"D":2,"E":3,"F":3,"G":3,"H":3,"I":1,"J":1,"K":3,"L":1,"M":3,"N":3,"O":1,"P":2,"Q":2,"R":2,"S":1,"T":2,"U":1,"V":1,"W":2,"X":2,"Y":2,"Z":1}
lst = list(map(lambda ch : di[ch],s))
ans = None
while len(lst) > 1:
    ans = 0
    lst_new = []
    for i in range(0,len(lst),2):
        if i == len(lst)-1:
            lst_new.append(lst[i])
            ans += lst[i]
        else:
            ans += lst[i]+lst[i+1]
            lst_new.append(lst[i]+lst[i+1])

    lst = lst_new

if ans is None:
    ans = lst[0]
    print("I'm a winner!" if ans % 2 == 1 else "You're the winner?")
else:
    print("I'm a winner!" if ans%2 == 1 else "You're the winner?")
