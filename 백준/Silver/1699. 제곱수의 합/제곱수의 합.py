import sys
import math
sys.setrecursionlimit(1000000)
ans_dict: dict[int,int] = dict()
ans_dict[1] = 1
ans_dict[2] = 2
ans_dict[3] = 3
ans_dict[4] = 1
N = int(input())

def f(n: int):
    if n in ans_dict:
        return ans_dict[n]
    if n == 0:
        return 0

    max_sqrt = int(math.sqrt(n)) # 예를들어 15면 max_sqrt는 3
    min_ans = 2100000000
    for sq in range(max_sqrt,0,-1):
        pow = sq**2 # ex) 9
        if n - pow < 0:
            continue
        # n이 15고 sq가 3이면
        # ex) 15 = 9 + f(6)
        min_ans = min(min_ans,1+f(n-pow))
    ans_dict[n] = min_ans
    return min_ans

print(f(N))