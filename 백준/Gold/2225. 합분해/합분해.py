from collections import deque

dp = dict() # key : tuple[n,k]  | value : int (단, 1,000,000,000보다 작은 값)

DIVIDE = 1000000000
N,K = map(int,input().split())
def f(n,k):
    if (n,k) in dp:
        return dp[(n,k)]

    assert not (n==0 and k==0)


    if k==1:
        return 1
    elif n==0:
        return 1

    acc = 0
    for next_n in range(0,n+1):
        acc += f(next_n,k-1)%DIVIDE

    # for next_n in range(0,n//2+1):
    #     for next_k in range(1,k//2+1): # k-1까지
    #         # if n==N and k==K:
    #         #     print(f"f({next_n},{next_k}) + f({n-next_n},{k-next_k})")
    #         acc += (f(next_n,next_k)%DIVIDE + f(n-next_n,k-next_k))%DIVIDE

    dp[(n,k)] = acc%DIVIDE
    return acc%DIVIDE

print(f(N,K))

