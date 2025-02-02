import sys
sys.setrecursionlimit(1000000)
DIVIDE = 1000000
ans:dict[tuple[int,str,str,str,int],int] = dict() # depth, b1, b2, lcnt

N = int(input())

def f(depth: int,c1: str,c2: str,c3: str,lcnt: int) -> int:
    # 주의 : lcnt는 c1까지 포함해서의 l개수임
    if lcnt >= 2:
        return 0


    if depth == N:
        if c1=='A' and c2=='A' and c3=='A':
            return 0
        else:
            ans[(depth,c1,c2,c3,lcnt)] = 1
            return 1


    if (depth,c1,c2,c3,lcnt) in ans:
        return ans[(depth,c1,c2,c3,lcnt)]

    if c1 == 'L':
        a = f(depth+1, 'L', c1, c2, lcnt+1)%DIVIDE
        a += f(depth+1, 'O', c1, c2, lcnt)%DIVIDE
        a += f(depth+1, 'A', c1, c2, lcnt)%DIVIDE
        ans[(depth, c1, c2, c3, lcnt)] = a%DIVIDE
        return a%DIVIDE

    if c1 == 'O':
        a = f(depth+1,'L',c1,c2,lcnt+1)%DIVIDE
        a += f(depth+1,'O',c1,c2,lcnt)%DIVIDE
        a += f(depth+1,'A',c1,c2,lcnt)%DIVIDE
        ans[(depth, c1, c2, c3, lcnt)] = a%DIVIDE
        return a%DIVIDE

    if c1 == 'A':
        if c2 == 'A' and c3 == 'A':
            a = 0
        else:
            a = f(depth+1,'L',c1,c2,lcnt+1)%DIVIDE
            a += f(depth+1, 'O', c1, c2, lcnt)%DIVIDE
            a += f(depth+1, 'A', c1, c2, lcnt)%DIVIDE
        ans[(depth, c1, c2, c3, lcnt)] = a%DIVIDE
        return a%DIVIDE
    raise "err"

a1 = f(1,'A','','',0)%DIVIDE # XXXA
a2 = f(1,'L','','',1)%DIVIDE # XXXL
a3 = f(1,'O','','',0)%DIVIDE # XXXO

print((a1%DIVIDE+a2%DIVIDE+a3%DIVIDE)%DIVIDE)
# real_ans = 0
# for c1 in ('A','O','L',''):
#     for c2 in ('A','O','L',''):
#         for c3 in ('A','O','L',''):
#             for lc in (0,1):
#                 if (N,c1,c2,c3,lc) in ans:
#                     real_ans+=ans[(N,c1,c2,c3,lc)]%DIVIDE
# print(real_ans)
