import sys
sys.setrecursionlimit(1000000)

N = int(input())
v = [0]
for _ in range(N):
    v.append(int(input()))

ans_dict: dict[tuple[int,bool,bool,bool],int] = dict()

def f(n: int, drink_cur: bool, drink_before1: bool, drink_before2: bool) -> int:
    if (n,drink_cur,drink_before1,drink_before2) in ans_dict:
        return ans_dict[(n,drink_cur,drink_before1,drink_before2)]
    # 아예 불가능한 경우
    if drink_cur and drink_before1 and drink_before2:
        return 0
    if n == 1:
        if drink_cur:
            return v[1]
        else:
            return 0
    case1 = f(n-1,True,drink_cur,drink_before1)
    case2 = f(n-1,False,drink_cur,drink_before1)
    max_case = max(case1,case2)
    if drink_cur:
        ans_dict[(n,drink_cur,drink_before1,drink_before2)] = v[n] + max_case
    else:
        ans_dict[(n, drink_cur, drink_before1, drink_before2)] = max_case
    return ans_dict[(n, drink_cur, drink_before1, drink_before2)]



ans1 = f(N,True,False,False)
ans2 = f(N,False,False,False)
print(max(ans1,ans2))

