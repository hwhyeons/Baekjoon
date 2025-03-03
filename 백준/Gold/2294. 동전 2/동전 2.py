import sys
sys.setrecursionlimit(1000000)
coins = []
N,K = map(int,input().split())
for _ in range(N):
    coins.append(int(input()))

coins = sorted(set(coins))

ERROR = 100000000
dp = dict()
def f(num):
    if num in dp:
        return dp[num]
    min_ans = ERROR
    for c in coins:
        if c == num:
            min_ans = 1 # 15원을 만들고 싶은데 15원짜리 동전이 존재하는 경우
            break
        elif c < num:
            # 현재 원하는게 f(15)인데 5원짜리 동전을 만난 경우
            local_ans = f(num-c)
            if local_ans == ERROR: # num=15고 c=5인데 f(10)이 불가능한 경우
                continue
            min_ans = min(min_ans,1+local_ans) # 5원짜리 동전 '1개' + f(10)
        elif c > num: # 정렬되어있으므로 중단
            break
    
    dp[num] = min_ans
    return dp[num]


# 최종적으로도_안되는경우_-1출력
last_ans = f(K)
if last_ans == ERROR:
    print(-1)
else:
    print(last_ans)

