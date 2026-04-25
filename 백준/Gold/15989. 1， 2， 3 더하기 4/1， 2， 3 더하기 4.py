
T = int(input())

# dp[r][c]는 r원을 만들기 위해 무조건 c동전을 적어도 하나 사용하는 경우
dp = [[0]*(3+1) for _ in range(10001)]

dp[1][1] = 1
dp[2][1] = 0
dp[2][2] = 1
dp[2][3] = 0
dp[3][1] = 1
dp[3][2] = 1 # 1+2
dp[3][3] = 1


for r in range(1,10001):
    for c in range(1,4):
        # 이번 DP는 dp[r][c]는 c원 동전을 무조건 사용하는 경우로 잡았으므로 사용이 불가능하면 스킵
        if r < c:
            continue
        # 예를들어 5원을 만들고자하고 3원짜리인 경우
        # 2원을 3원짜리 없이 만드는 경우에서 3을 붙이기 (이 경우 c-1,c-2)
        # 2원을 3원짜리 가지고 만드는 경우에서 3을 붙이기
        case1 = 0
        if c-2>=0: # c=3이면 1원짜리만 사용한 경우에서 3원 붙이는 경우
            case1 = dp[r-c][c-2]
        case2 = 0
        if c-1>=0:
            case2 = dp[r-c][c-1] # c=3이면 2원짜리를 적어도 한개 사용한 경우에서 3원짜리 붙이기

        case3 = dp[r-c][c] # c=3이면 3원짜리를 적어도 한개 사용한 경우에서 3원짜리 붙이기
        dp[r][c] = max(dp[r][c], case1+case2+case3)


for _ in range(T):
    N = int(input())
    print(sum(t for t in dp[N]))

