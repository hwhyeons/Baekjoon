import sys
sys.setrecursionlimit(1000000)
DIVIDE = 1000000
ans:dict[tuple[int,str,str,str,int],int] = dict() # depth, b1, b2, lcnt

N = int(input())

def f(depth: int,c1: str,c2: str,c3: str,lcnt: int) -> int:
    if c1=='A' and c2=='A' and c3=='A':
        return 0
    if lcnt >= 2:
        return 0
    if depth == 1:
        if c1 == 'L' and c2 == 'L':
            return 0
        return 1


    if (depth,c1,c2,c3,lcnt) in ans:
        return ans[(depth,c1,c2,c3,lcnt)]

    a = 0
    a += f(depth-1,'A',c1,c2,lcnt)%DIVIDE
    a += f(depth-1,'O',c1,c2,lcnt)%DIVIDE
    a += f(depth-1,'L',c1,c2,lcnt+1)%DIVIDE
    ans[(depth,c1,c2,c3,lcnt)] = a%DIVIDE
    return a%DIVIDE


a1 = f(N,'A','','',0)%DIVIDE # XXXA
a2 = f(N,'L','','',1)%DIVIDE # XXXL
a3 = f(N,'O','','',0)%DIVIDE # XXXO
# print("a1 :",a1)
# print("a2 :",a2)
# print("a3 :",a3)
print((a1%DIVIDE+a2%DIVIDE+a3%DIVIDE)%DIVIDE)
